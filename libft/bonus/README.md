## Bonus Part
- Makefile에 bonus 추가

<br>

*`t_list *lst`일 때, `lst`가 0이면 아예 리스트가 없는 거고, `*lst`가 0이면 빈 리스트인 것*

01. lstnew
    - **`t_list *ft_lstnew(void *content)`**
    - content : 새로운 노드에 들어갈 데이터
    - return : 생성된 노드의 주소값
    - 새로운 노드를 생성하는 함수

02. latadd\_front
    - **`void ft_lstadd_front(t_list **lst, t_list *new)`**
    - lst : `head node`를 가리키는 포인터 주소
    - new : 리스트에 붙일 새로운 노드
    - 새로운 노드를 리스트의 맨 앞에 이어붙이는 함수
    - `lst`는 연결리스트의 `head node`를 담고 있음
    - `\*lst`는 `head node`의 주소를 의미함
    - `\**lst`는 `head node`가 가진 값을 의미함

03. lstsize
    - **`int ft_lstsize(t_list *lst)`**
    - lst : 리스트의 `head node`
    - return : 노드의 개수
    - 리스트의 노드가 몇 개인지 세어 반환하는 함수

04. lstlast
    - **`t_list *ft_lstlast(t_list *lst)`**
    - lst : 리스트의 `head node`
    - return : 마지막 노드의 주소값
    - 리스트의 가장 마지막 노드를 반환하는 함수

05. lstadd\_back
    - **`void ft_lstadd_back(t_list **lst, t_list *new)`**
    - lst : `head node`를 가리키는 포인터 주소
    - new : 리스트에 붙일 새로운 노드
    - 새로운 노드를 리스트의 맨 마지막에 이어붙이는 함수
    - `lst`는 연결리스트의 `head node`를 담고 있음
    - `\*lst`는 `head node`의 주소를 의미함
    - `\**lst`는 `head node`가 가진 값을 의미함

06. lstdelone
    - **`void ft_delone(t_list *lst, void (*del)(void *))`**
    - lst : 리스트의 `head node`
    - del : 노드의 content를 삭제할 때 사용할 함수를 가리키는 포인터
    - 노드를 삭제하는 함수

07. lstclear
    - **`void ft_clear(t_list **lst, void (*del)(void *))`**
    - lst : `head node`를 가리키는 포인터 주소
    - del : 노드의 content를 삭제할 때 사용할 함수를 가리키는 포인터
    - 리스트의 전체 노드를 지우고 빈 리스트로 만드는 함수

08. lstiter
    - **`void ft_lstiter(t_list *lst, void (*f)(void *))`**
    - lst : 리스트의 `head node`
    - f : 노드의 content에 적용할 함수를 가리키는 포인터
    - lst의 content에 함수 f를 적용하는 함수

09. lstmap
    - **`t_list *ft_lstmap(t_list *s, void *(*f)(void *), void (*d)(void *))`**
    - s : 리스트의 `head node`
    - f : 노드의 content에 적용할 함수를 가리키는 포인터
    - d : 노드의 content를 삭제할 때 사용할 함수를 가리키는 포인터
    - return : 새로운 리스트 or 실패시 `NULL`
    - lst의 content에 함수 f를 적용해 새로운 리스트를 만들어 반환하는 함수
