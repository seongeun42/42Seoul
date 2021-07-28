## Part 1. Libc Functions

- libc(C 표준 라이브러리) 내의 함수를 man에 정의된 대로 구현한다.
- 원본 함수와 동일하게 프로토타입과 기능을 구현해야 한다.
- 원본 함수에 `restrict` 키워드가 있는 경우 제외한다.

---

01. memset
    - **`void *ft_memset(void *dest, int value, size_t size)`**  
    - dest : setting하고자 하는 메모리의 시작 주소  
    - value : setting하고자 하는 값  
    - size : 메모리의 크기(ex. 5개짜리 문자열(arr)이면 `5 * sizeof(char)` or `sizeof(arr)`, 2개짜리 정수 배열(num)이면 `2 * sizeof(int`) or `sizeof(num)`)
    - return : 초기화가 잘됐을 경우 메모리의 시작 주소 반환 or 초기화 실패시 `NULL` 반환
    - [할당된 메모리를 byte 단위로 value값으로 초기화하는 함수](https://blog.naver.com/chogahui05/221484049429)
    - byte 단위로 초기화하기 때문에 원하는 대로 초기화가 안 될 수 있음. 그래서 주로 0으로 초기화함
    
02. bzero
    - **`void ft_bzero(void *str, size_t n)`**
    - str : setting하고자 하는 메모리의 시작 주소
    - n : 메모리의 크기(ex. 5개짜리 문자열이면 `5 * sizeof(char)`, 2개짜리 정수 배열이면 `2 * sizeof(int)`)
    - 할당된 메모리를 0으로 초기화하는 함수
    - 사용하면 bzero 대신 memset을 쓰라고 뜸
    
03. memcpy
    - **`void *ft_memcpy(void *dest, const void *src, size_t size)`**
    - d : 복사되는 메모리의 첫번째 주소
    - s : 복사할 메모리의 첫번째 주소
    - size : 복사할 길이
    - return : dest의 주소 or 복사 실패시 `NULL`
    - dest에 src를 size byte만큼 복사하는 함수
    - `strcpy`와 달리 널문자를 검사하지 않아 널문자를 만나도 복사를 멈추지 않고 계속 함
    - `strcpy`가 문자를 검사하며 복사를 진행한다면, `memcpy`는 검사하지 않고 정해진 size만큼 복사하기 때문에 좀 더 빠름
    - `memmove`와 달리 메모리의 내용을 직접 복사하기 때문에 속도가 더 빠름
    - 직접 복사로 동작하기 때문에 `memmove`와 달리 d와 s의 메모리가 겹칠 경우 제대로 복사되지 않음(안정성 떨어짐)
    
04. memccpy
    - **`void *ft_memccpy(void *d, const void *s, int c, size_t n)`**
    - d : 복사되는 메모리의 첫번째 주소
    - s : 복사할 메모리의 첫번째 주소
    - c : 복사를 멈출 문자
    - n : 복사할 길이
    - return : c를 찾았으면 c까지 복사된 메모리의 다음 주소값 반환 or c가 없으면 n만큼 다 복사한 후 `NULL` 반환
    - dest에 src를 src에 n byte만큼 복사하되, c가 있을 경우 c까지만 복사하는 함수
    - `memmove`와 달리 메모리의 내용을 직접 복사하기 때문에 속도가 더 빠름
    - 직접 복사로 동작하기 때문에 `memmove`와 달리 d와 s의 메모리가 겹칠 경우 제대로 복사되지 않음(안정성 떨어짐)
    
05. memmove
    - **`void *ft_memmove(void *dest, const void *src, size_t len)`**
    - d : 복사되는 메모리의 첫번째 주소
    - s : 복사할 메모리의 첫번째 주소
    - len : 복사할 크기
    - return : dest의 주소 or 복사 실패시 `NULL`
    - dest로 src를 len만큼 복사하는 함수
    - `memcpy`나 `memccpy`와 달리 src의 데이터를 임시공간에 복사해놨다가 dest에 복사하는 식으로 동작함
    - `memcpy`나 `memccpy`와 달리 메모리 주소가 겹칠 경우에도 안정적인 복사가 가능함
    
06. memchr
    - **`void *ft_memchr(const void *s, int c, size_t n)`**
    - s : 탐색될 메모리의 주소
    - c : 찾을 문자
    - n : 탐색할 최대 크기
    - return : c가 있는 주소값 or 찾지 못하면 `NULL`
    - s에 문자 c가 있는지 탐색해서 결과를 반환하는 함수

07. memcmp
    - **`int ft_memcmp(const void *s1, const void *s2, size_t n)`**
    - s1 : 비교할 메모리의 주소
    - s2 : 비교할 메모리의 주소
    - n : 비교할 크기
    - return : 두 메모리가 같으면 0 or s1이 크면 1(양수) or s2가 크면 -1(음수)
    - s1과 s2가 같은지 다른지 비교하는 함수
    - `strcmp`는 문자열을 비교해서 둘 다 널문자가 나오면 멈추지만, `memcmp`는 둘 다 널문자가 나오더라도 멈추지 않고 두 값이 다르거나 n만큼 확인할 때까지 비교함
    
08. strlen
    - **`size_t ft_strlen(const char *str)`**
    - str : 길이를 잴 문자열
    - return : 문자열의 길이
    - 널문자를 제외한 문자열의 길이를 재서 반환하는 함수
    
09. strlcpy
    - **`size_t ft_strlcpy(char *dest, const char *src, size_t size)`**
    - dest : 목적지 버퍼
    - src : 복사될 문자열
    - size : 복사할 길이
    - return : dest의 길이 값
    - 널문자를 넣어 문자열의 끝을 보장함으로 써 안정성을 높인, dest에 src를 size만큼 복사하는 함수
    - size는 널문자를 포함하므로, 실제 복사되는 문자는 `size - 1`개
    
10. strlcat
    - **`size_t ft_strlcat(char *dest, const char *src, size_t size)`**
    - dest : 합쳐질 문자열(목적지 버퍼)
    - src : 붙여넣어질 문자열
    - size : 전체 버퍼의 크기
    - return : dest > size면 src + size, dest < size면 src + dest
    - 널문자를 넣어 문자열의 끝을 보장함으로 써 안정성을 높인, dest에 src를 합치는 함수
    
11. strchr
    - **`char *ft_strchr(const char *s, int c)`**
    - s : 탐색 대상 문자열
    - c : 탐색 목표 문자
    - return : s 문자열 앞에서부터 탐색했을 때 가장 처음 나온 c의 주소 or 찾는 게 없으면 NULL
    - 문자열 s에서 문자 c가 있는지 탐색해서 있다면 그 문자열이 있는 주소를 반환하는 함수
    - [문자를 char가 아니라 int로 주는 이유](https://stackoverflow.com/questions/2394011/why-does-strchr-take-an-int-for-the-char-to-be-found?fbclid=IwAR0A6Y9nLqtNo_W4EDWcWlLUT6_cxvp7RqOBc69eCwOEsKouoYI69O_m2Fo)
    - 널문자도 문자열의 일부로 간주하기 때문에 문자열의 맨 끝을 가리키는 용도로 사용하기도 함
    - c는 널문자일 수 있음
    
12. strrchr
    - **`char *ft_strrchr(const char *s, int c)`**
    - s : 탐색 대상 문자열
    - c : 탐색 목표 문자
    - return : s 문자열 뒤에서부터 탐색했을 때 가장 처음 나온 c의 주소 or 찾는 게 없으면 NULL
    - 문자열 s에서 문자 c가 있는지 탐색해서 있다면 그 문자열이 있는 주소를 반환하는 함수
    - c는 널문자일 수 있음
    
13. strnstr
    - **`char *ft_strnstr(const char *str, const char *to_find, size_t len)`**
    - str : 탐색 대상 문자열
    - to_find : 탐색 목표 문자열
    - len : 탐색할 최대 길이
    - return : str에 to_find가 있으면 찾은 문자열이 시작되는 주소 or 못 찾으면 0 or to_find가 비었으면 str 전체
    - str 문자열 내에 to_find 문자열이 있는지 탐색해, 있다면 그 시작 주소를 반환하는 함수
    - len이 str의 전체 길이보다 클 경우 str의 문자열 끝까지 탐색함
    - 널문자를 만나면 탐색 중단
    
14. strncmp
    - **`int ft_strncmp(const char *s1, const char *s2, size_t n)`**
    - s1, s2 : 비교할 문자열들
    - n : 비교할 최대 size
    - return : 같으면 0, s1이 더 크면 양수, s2가 더 크면 음수
    - 두 개의 문자열을 비교해 문자열이 같으면 0, 다르면 음수 또는 양수를 반환하는 함수
    - n은 `size_t`형이라 음수를 넣으면 오버플로우 발생해서 `size_t`의 최대값까지 돌게 됨
    
15. atoi
    - **`int ft_atoi(const char *str)`**
    - str : `int`형 정수로 변환하고자 하는 문자열
    - return : `int`형 정수 or 변환할 수 없다면 0
    - 문자열로 된 숫자를 `int`형 정수로 변환하는 함수
    - 문자열 앞의 공백은 처리하되, 부호는 1개만 허용하며, 숫자 다음에 숫자 이외의 것이 나오면 변환 중단
    - 확인해보니까 따로 양수 오버플로우는 -1, 음수 오버플로우는 0으로 나오도록 처리 안 해도 원본과 똑같이 처리됨
    
16. isalpha
    - **`int isalpha(int c)`**
    - 문자 c가 알파벳인지 판별하는 함수
    - return : 0 or 1
    
17. isdigit
    - **`int isdigit(int c)`**
    - 문자 c가 숫자인지 판별하는 함수
    - return : 0 or 1
    
18. isalnum
    - **`int isalnum(int c)`**
    - 문자 c가 알파벳 및 숫자인지 판별하는 함수
    - return : 0 or 1
    
19. isascii
    - **`int isascii(int c)`**
    - 문자 c가 아스키코드 내의 문자인지 판별하는 함수
    - return : 0 or 1
    
20. isprint
    - **`int isprint(int c)`**
    - 문자 c가 출력 가능한 문자인지 판별하는 함수
    - return : 0 or 1
    
21. toupper
    - **`int ft_toupper(int c)`**
    - 문자 c가 소문자면 대문자로 변환하는 함수
    - return : 대문자로 변환된 c
    
22. tolower
    - **`int ft_tolower(int c)`**
    - 문자 c가 대문자면 소문자로 변환하는 함수
    - return : 소문자로 변환된 c
    
23. calloc
    - **`void *ft_calloc(size_t count, size_t size)`**
    - count : 할당할 메모리 공간 개수
    - size : 할당할 공간의 크기
    - return : 할당된 메모리를 가리키는 포인터 or 할당 실패시 `NULL`
    - `malloc`처럼 동적할당을 위한 함수로, 공간 할당 후 0으로 초기화해줌
    
24. strdup
    - **`char *ft_strdup(const char *src)`**
    - src : 복제할 문자열
    - return : 복제된 문자열 or 복제 실패 시 NULL
    - src를 함수 내에서 `malloc`을 사용해 복사한 후 복제된 문자열을 반환하는 함수
    - 복제된 문자열이 필요하지 않으면 반드시 `free` 함수를 사용해 해제해주어야 함
    - `strcpy` 함수와의 차이 : `strcpy`는 dest의 크기가 src보다 작으면 문자열이 짤리지만, `strdup`은 문자열을 완벽하게 복제해줌
  
  
  
*mem 계열 함수와 str 계열 함수의 차이는, 메모리를 비교하느냐와 문자열을 비교하느냐임*  
*mem 계열 함수는 널문자를 체크하지 않고, str 계열 함수는 널문자를 체크함(문자열의 끝은 널문자니까)*
