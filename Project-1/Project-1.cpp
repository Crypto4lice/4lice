#include <iostream>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

void main() {
	/*
		극단적인 수의 규칙을 찾아내기 위해 수를 순차적으로 나열해보자
		(1,4) (2,7) (3,44) (4,47) (5,74) (6,77) (7,444) (8,447) (9,474) (10,477)
		(11,744) (12,747) (13,774) (14,777) (15, 4444) ...

		이렇게 수를 나열하다보면 극단적인 수의 길이에 대한 하나의 규칙1을 찾을 수 있다.

		길이 = L에 관해서 L = 1인 수는 1, 2
						 L = 2인 수는 3, 4, 5, 6
						 L = 3인 수는 7, 8, 9, 10, 11, 12, 13, 14

						 L이 가지고 있는 수의 범위는 이와 같이 나타낼 수 있다. (2^L - 1) ~ 2*(2^L - 1)

		Binary Search를 이용하여 원하는 숫자를 구하기위해
		
		left = (2^L -1) right = 2*(2^L -1)+1로 설정한다.

		규칙2를 찾기 위해서 K를 이용해 길이 L을 구하자.
		K = (2^L - 1) 이므로 이를 이항정리를 통해 L을 구하면
		L = ln(K+1)/ln2 가 된다.

		다음 이들의 관계를 살펴보자 (7,444) (8,447) (9,474) (10,477) (11,744) (12,747) (13,774) (14,777)
		N = 7,  L = 3
		7번째의 경우 444가 출력되야 하므로 for문을 이용하여 i = 0 부터 i<L까지
		1. left = 7 right = 15 mid = 11
		mid 가 K보다 클 경우 4를 출력 right = mid;					4
		left = 7 right = 11 mid = 9
		mid 가 K보다 클 경우 4를 출력 right = mid;					4 4
		left = 7 right = 9 mid = 8
		mid 가 K보다 클 경우 4를 출력 right = mid;					4 4 4
		
		L = 3이므로 444를 출력하고 프로그램 종료

	*/
	int N, L;
	cin >> N;
	L = log(N + 1) / log(2);
	int left = pow(2, L) - 1;
	int right = 2 * (pow(2, L) - 1) + 1;
	for(int i = 0; i<L;i++){
		int mid = (left + right) / 2;
		if (mid > N) {
			cout << "4";
			right = mid;
		}
		else {
			cout << "7";
			left = mid;
		}
	}
	cout << endl;
}