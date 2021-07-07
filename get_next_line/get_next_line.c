/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:15:17 by seongele          #+#    #+#             */
/*   Updated: 2021/06/15 19:38:21 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 개행 문자 찾아서 인덱스 반환하는 함수, 널문자 만나면 -1 반환
int	find_nl(char *str)
{
	size_t i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

// line에 찾은 한 문장(마지막 문장 제외)을 넣어주기 위한 함수
int	one_line(char **str, char **line, int idx)
{
	// backup를 바꿀 때 사용할 임시 문자열
	char *tmp;

	// 만약 현재 문장이 비어서 개행문자만 있는 경우
	if ((*str)[0] == '\n')
		// line에 빈 문자열을 대입
		*line = ft_strdup("");
	// 문장이 비어 있지 않은 경우
	else
		// ft_substr로 개행문자가 나오기 전까지 line에 대입
		*line = ft_substr(*str, 0, idx);
	// ft_substr 실패해서 *line이 0이면
	if (!line)
		// backup을 free해주고 -1을 반환
		return (str_free(str));
	// 아니면 backup의 내용을 복사해 tmp에 넣기
	tmp = ft_strdup(*str);
	// ft_strdup 실패해서 tmp가 0이면
	if (!tmp)
		// backup을 free해주고 -1을 반환
		return (str_free(str));
	// line에 넣어준 문장을 제외한 나머지로 backup의 내용을 바꾸기 전에 현재 backup은 free해줌
	free(*str);
	// tmp에 복사해뒀던 내용으로 개행문자 다음부터 끝까지로 이루어진 새로운 문자열을 backup으로 만듦
	*str = ft_substr(tmp, idx + 1, ft_strlen(tmp) - idx - 1);
	// ft_substr 실패해서 *str이 0이면 backup free하고 -1 반환
	if (!*str)
		return (str_free(str));
	// 만약 새로 만들어진 backup이 비어 있다면, backup을 해제해줌
	if (!**str)
		str_free(str);
	// 복사해둔 내용을 free시킴
	free(tmp);
	tmp = 0;
	// 문장을 line에 잘 넣었으니까 1을 반환
	return (1);
}

int	line_return(char **str, char **line, int idx, int read_size)
{
	// 만약 제대로 된 파일을 연 게 아니라 read가 실패해서 -1을 받은 경우
	if (read_size < 0)
		// backup을 free해주고 -1을 반환
		return (str_free(str));
	// 만약 파일을 다 읽어온 상태고(read_size == 0), 개행문자가 아니라 널문자를 찾은 경우(idx == -1) => 마지막 문장
	else if (!read_size && idx == -1)
	{
		// 마지막 문장이니까 backup에 남은 모든 문자열을 line에 넣어줌
		*line = ft_strdup(*str);
		// ft_strdup()이 실패해서 *line이 0이면 backup을 free하고 -1 반환
		if (!line)
			return (str_free(str));
		// 더 이상 backup을 쓰지 않으니까 backup을 free해줌
		str_free(str);
		// 마지막 문장까지 다 읽어서 EOF에 도달했으니 0을 반환
		return (0);
	}
	// 마지막 문장이 아닌 나머지 경우
	return (one_line(str, line, idx));
}

int	get_next_line(int fd, char **line)
{
	// 여러 개의 파일을 열 때를 대비해, 최대 열 수 있는 파일의 개수인 256 크기로 선언
	// 문자열을 가리키는 256개의 포인터를 담을 수 있음 
	// static으로 선언해서 내용이 지워지지 않음
	// -> 데이터 영역에 저장되는데, 데이터 영역은 프로세스가 실행될 때 저장되고, 종료될 때 지워짐
	// 내용이 유지되어야 하는 이유 :
	// 버퍼 사이즈만큼 읽어왔어도 문장이 끝나지 않은 경우 한 문장이 나올 때까지 계속 읽어와야 하는데,
	// 이미 읽어온 내용을 저장해뒀다가 새로 읽어온 내용과 합쳐야하기 때문에
	static char	*backup[256];
	// read 함수로 읽어온 파일 내용을 저장할 버퍼로, +1은 널문자를 넣어줄 공간
	char		buff[BUFFER_SIZE + 1];
	// read 함수가 몇 byte나 읽어왔는지 반환받을 변수
	int			read_size;
	// 문장에 개행문자가 있는지 확인한 결과를 담기 위한 변수
	int			check;

	// 만약 line이 널포인터거나, fd가 음수거나, 최대값보다 크거나, 버퍼 크기가 1보다 작은 경우 -1 반환
	if (!line || fd < 0 || fd > 255 || BUFFER_SIZE < 1)
		return (-1);
	// 만약 backup[fd]가 널포인터라면, 빈문자열로 만들어줌
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	// ft_strdup이 실패했으면 -1 반환
	if (!backup[fd])
		return (-1);
	// 파일을 BUFFER_SIZE만큼 읽어옴
	read_size = read(fd, buff, BUFFER_SIZE);
	// 만약 제대로 된 파일이고, 파일을 다 읽지 않았다면 반복문 돎
	while (read_size > 0)
	{
		// 파일이 읽어온 문장 끝에 널문자를 넣어줌
		buff[read_size] = '\0';
		// backup에 있는 문장과 새로 읽어온 문장을 합쳐서 backup에 저장
		// free_strjoin으로 문장을 합친 새로운 문자열을 가리키게 함
		// backup이 원래 가리키고 있던 이전 문장은 join함수 안에서 마지막에 free해줌
		backup[fd] = free_strjoin(backup[fd], buff);
		// strjoin 실패해서 backup[fd]가 0이면 -1 반환
		if (!backup[fd])
			return (-1);
		// 문장 안에 개행 문자가 있는지 확인
		// 있으면 개행 문자가 있는 위치(인덱스)값을 받게 되고, 아니면 -1
		check = find_nl(backup[fd]);
		// 만약 하나의 문장을 찾았다면
		if (check != -1)
			// line에 찾은 문장을 넣어주고 1을 반환
			// backup은 찾은 문장을 제외한 남은 문장만 남게 업데이트 됨
			return (line_return(&backup[fd], line, check, read_size));
		// 만약 개행 문자가 없어 아직 하나의 문장을 찾지 못했다면 파일을 더 읽어옴
		read_size = read(fd, buff, BUFFER_SIZE);
	}
	// 파일을 다 읽어온 상태일 때 버퍼 내의 문장을 찾기 위해 개행 문자 확인
	check = find_nl(backup[fd]);
	// check가 인덱스면 문장, -1이면 마지막 문장
	return (line_return(&backup[fd], line, check, read_size));
}
