## libft 구현 과정에서 공부한 것들

### [Makefile](https://bowbowbow.tistory.com/12#make-%EC%99%80-makefile)
- `make` 는 반복적으로 발생하는 컴파일을 쉽게 하기 위해 사용하는 파일 관리 유틸리티
- `Makefile`은 `make` 프로그램의 기술 파일로, `make`는 파일 간의 종속관계를 파악해 `Makefile`에 적힌 대로 컴파일러에 명령을 내림으로써 shell 명령어를 순차적으로 실행함
- `Makefile`과 `make`를 사용함으로써 반복적인 명령을 자동화해 효율적인 컴파일 작업이 가능해짐
- `Makefile`은 목표파일, 의존 파일, 명령으로 구성됨
- `Makefile` relink : 코드가 변경되지 않은 상태에서 다시 make를 실행했을 때, 최신 상태라 목적파일을 다시 만들지 않으면 relink되지 않은 것
  
<br>

1. 매크로
  - $@ : 현재 목표 파일명
  - $< : 현재 목표 파일보다 최근에 변경된 종속 항목의 리스트 중 첫번째 파일
  - $^ : 전체 의존 파일 목록
  
<br>

2. ar
  - 정적 라이브러리(아카이브) : 여러 오브젝트 파일들을 하나의 파일로 다룰 수 있도록 정리해 모아둔 것
  - `ar` : 정적 라이브러리를 만들 수 있는 명령어
  - 옵션
    - r : 지정한 파일이 새로운 오브젝트 파일이면 아카이브 파일에 추가하고, 기존 파일이면 해당 파일로 교체함
    - c : 아카이브 파일이 생성될 때 기본적으로 표준 에러로 출력되는 에러 메시지의 출력을 제한함
    - s : 아카이브 인덱스를 생성함 *인덱스를 작성하지 않으면 링크 속도가 느려짐*

<br>

---

<br>

### 메모리 관련
1. 메모리 구조
  - 메모리 공간은 코드, 데이터, 힙, 스택으로 나뉨
    |공간||
    |:---:|:---|
    |코드|작성한 소스 코드가 들어가는 부분<br>함수, 제어문, 상수 등이 여기로 들어감|
    |데이터|전역 변수와 `static` 변수가 할당되는 영역<br>프로그램이 시작되면 할당되고, 종료되면 소멸됨|
    |힙|개발자가 임의로 할당/해제 가능한 영역<br>동적할당된 변수는 여기에 저장됨|
    |스택|프로그램이 자동으로 사용하는 임시 메모리 영역<br>함수 호출 시 생성되는 지역 변수와 매개변수가 저장됨<br>함수 호출이 완료되면 사라짐|
  - 힙과 스택은 사실 같은 공간으로, 힙이 크면 스택이 작고, 스택이 크면 힙이 작음
  
<br>

2. static
  - 정적 키워드로, 정적 함수나 변수를 만들면 해당 함수나 변수가 있는 파일 내에서만 사용 가능함
  - 데이터 영역에 들어가기 때문에 프로그램이 종료될 때까지 지워지지 않고, 한번 초기화하면 다시 초기화할 수 없음(즉, 정적 변수는 값이 계속 유지됨)
  - 정적 함수는 기능이 여러 파일로 분리되어 있을 때 각 파일 안에서만 사용하는 기능을 구현하는 데 사용함
    
<br>

3. 동적 할당
  - 프로그램 실행 중 개발자가 원할 때 힙 영역에 원하는 크기의 메모리 공간을 할당하는 것
  
<br>

4. 메모리 누수
  - 동적으로 할당받은 메모리의 주소를 잃어버려 힙에 메모리를 반환할 수 없는 것, 혹은 필요하지 않은 변수를 적절하게 제거하지 않은 것
  - 메모린 누수가 계속되면 힙 영역이 꽉 차버려 더 이상 사용할 수 있는 자원이 없어지게 됨
  - 방지하기 위해서는 동적 할당된 변수가 더 이상 필요하지 않을 시 반드시 `free`를 사용해 힙에 반환해야 함
  
<br>

---

<br>

### [char와 unsigned char](https://m.blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221877901901&proxyReferer=https:%2F%2Fwww.google.com%2F)
- `char` : 8byte 중 가장 왼쪽의 비트를 부호 비트로 사용하기 때문에 -128~127까지 표현 가능함
- `unsigned char` : 8byte를 전부 데이터 비트로 사용하기 때문에 -256~255까지 표현 가능함
- ascii 코드 범위를 넘어서는 문자의 경우 `unsigned char`로 받아줘야 제대로 표현할 수 있음
  
<br>

---

<br>

### 파일 디스크립터(fd)
- 유닉스 계열 시스템에서 프로세스가 파일을 다룰 때 사용하는 개념
- 유닉스 계열 시스템에서는 일반 파일, 디렉토리, 입출력장치, 소켓 등의 모든 것을 파일로 관리하는데, 이 각각의 파일이 가지는 식별자의 개념임
- 새로운 파일을 사용하고자 하면 커널이 비어있는 파일 디스크립터 중 가장 작은 값을 알아서 할당함
- 기본적으로 0은 표준입력, 1은 표준출력, 2는 표준에러를 의미
- 파일 디스크립터는 0이 아닌 정수값을 가짐
  
<br>

---

<br>

### 함수 포인터
- `type (*f)(parameter)`
- 함수를 가리키는 포인터
- 함수도 주소를 가지기 때문에 포인터에 넣을 수 있음
- 사용하고자 하는 함수가 그때그때 다를 때 함수 포인터를 사용해 원하는 함수를 적용할 수 있음
  
<br>

---

<br>

### \*s가 있을 때, `\*s == 0`과 `s == 0`의 차이
- `\*s == 0` : 메모리 공간은 있는데, 데이터가 없는 경우
- `s == 0` : 메모리 자체가 할당되지 않은 널포인트 상태