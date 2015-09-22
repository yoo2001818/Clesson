Stack
=====

(Personal info redacted)

Stack의 정의
============

Stack이나 LIFO(Last in, first out)은 원소들의 집합으로써 push, pop 두 가지의 
작업을 수행할 수 있는 추상화 자료 구조이다.

Stack의 특징
============

Stack은 작업이 자료 구조의 한쪽 끝에서만 일어난다.

'LIFO'라는 말은, 'push'와 'pop'의 연속적인 조합에서 stack에서 'pop'된 요소는 가장 
최근에 'push'된 요소이기 때문에 이런 이름이 붙었다. 또 이는 선형 자료 구조가 필요로
하는 요구 사항과 같아서 Stack은 선형 자료 구조로 취급된다.

Stack은 제한된 용량을 가지게 구현될 수 있다. Stack이 꽉 차있고 더 이상 요소가 푸시 
될 공간이 없다면 stack은 'overflow' 상태라고 취급된다. pop은 stack에서 전에 저장된
데이터들을 꺼낸다. 하지만 stack이 비었다면, 'underflow' 상태로 취급되며 이는
stack에서 더이상 삭제할 수 있는 데이터가 없다는 것을 의미한다.

요소들이 stack에서 삭제되는 순서는 요소들이 stack에 추가된 순서의 반대이다.
따라서, stack의 가장 밑에 있던 요소가 stack에 제일 오랫동안 있던 요소가 된다.

Stack의 주요 동작 설정
=====================

- **push**. 집합의 끝에 요소를 추가한다.
- **pop**. 집합의 끝에 있던 요소를 제거한다.

Stack 구현
==========

대부분의 고급 언어에서는 stack을 배열이나 연결 리스트를 사용해 구현될 수 있다.
양쪽 모두 stack을 구현체로 사용하는 것이 아니라 인터페이스로써 사용하게 된다.
즉, 사용자는 배열이나 연결 리스트에 pop이나 push만을 수행할 수 있다.

출처
====
[위키백과 영문](http://en.wikipedia.org/wiki/Stack_(abstract_data_type)) 번역
