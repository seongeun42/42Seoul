## Part 2. Additional Functions

01. substr
    - **`char *ft_substr(char const *s, unsigned int start, size_t len)`**
    - s : 문자열의 시작 주소
    - start : 자를 위치
    - len : 복사할 길이
    - return : 자른 문자열의 시작 주소값 or 실패시 `NULL`
    - 문자열 s를 start번째부터 len만큼 자른 결과를 반환하는 함수
    - s의 전체 길이보다 start가 더 크면 빈문자열("") 반환

02. strjoin
    - **`char *ft_strjoin(char const *s1, char const *s2)`**
    - s1 : 앞에 붙일 문자열
    - s2 : 뒤에 붙일 문자열
    - return : s1과 s2를 합친 새로운 문자열 or 실패시 `NULL`
    - s1과 s2를 합친 새로운 문자열을 만들어 반환하는 함수

03. strtrim
    - **`char *ft_strtrim(char const *s1, char const *set)`**
    - s1 : 처리할 문자열
    - set : 제거될 문자 모임
    - return : set에 포함된 문자가 제거된 문자열 or 실패시 `NULL`
    - set에 포함된 문자를 문자열 s1의 앞뒤에서 제거하는 함수

04. split
    - **`char **ft_split(char const *s, char c)`**
    - s : 처리할 문자열
    - c : 구분자
    - return : 단어가 담긴 배열을 반환 or 실패시 `NULL`
    - 문자열 s를 구분자 c를 기준으로 쪼개어(즉, 문장을 단어로) 문자열 배열에 담아 반환하는 함수

05. itoa
    - **`char *ft_itoa(int n)`**
    - n : 정수 값
    - return : 문자열로 변환된 n값 or 실패시  `NULL`
    - 정수 값 n을 문자열 n으로 변환해 반환하는 함수

06. strmapi
    - **`char *ft_strmapi(char const *s, char (*f)(unsigned int, char))`**
    - s : 처리할 문자열
    - f : 적용할 함수
    - return : f가 적용된 후의 문자열 or 실패시 `NULL`
    - 문자열 s에 함수 f를 적용한 결과를 반환하는 함수

07. putchar
    - **`void ft_putchar_fd(char c, int fd)`**
    - c : 출력할 문자
    - fd : 파일 디스크립터 인덱스
    - 문자 하나를 write 함수를 사용해 출력하는 함수

08. putstr
    - **`void ft_putstr_fd(char *s, int fd)`**
    - s : 출력할 문자열
    - fd : 파일 디스크립터 인덱스
    - 문자열을 write 함수를 사용해 출력하는 함수

09. putendl
    - **`void ft_putendl_fd(char *s, int fd)`**
    - s : 출력할 문자열
    - fd : 파일 디스크립터 인덱스
    - 문자열을 write 함수를 사용해 출력하되 줄바꿈도 같이 출력하는 함수

10. putnbr
    - **`void ft_putnbr_fd(int n, int fd)`**
    - n : 출력할 정수 값
    - fd : 파일 디스크립터 인덱스
    - 정수 n을 write 함수를 사용해 출력하는 함수
