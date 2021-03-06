# SJU-Subject <br>
Eng : Repository to store Assignments and Homeworks from Sejong University <br>

Kor : 이 저장소는 세종대학교에서 이루어지는 수업에서 작성한 코드들을 보관합니다.


<h1>Grade 2 (2019)</h1>

<br>
<h2>Data Structure</h2>

| Semester | Professor | Lecture Name | Language | Lecture Hours / week | Credit | GradePoint (A~D,F) |
|:--------|:--------|:--------|:--------|:---------|:---------|:---------|
| First | ys Cho | Data Structure  | Korean | 5hours / week | 4 | B+ (3.5) |
| 1학기 | 조윤식 | 자료구조 및 실습  | 한국어 | 5시간 / 주 | 4 | B+ (3.5)|


<br>
<h2>Basic of Data Analysis</h2>

| Semester | Professor | Lecture Name | Language | Lecture Hours / week | Credit | GradePoint (A~D,F) |
|:--------|:--------|:--------|:--------|:---------|:---------|:---------|
| First | jw Song | Basic of <br>Data Analysis  | Kor, Eng | 3hours / week | 3 |A+ (4.5)|
| 1학기 | 송재욱 | 데이터분석개론  | 한국어, 영어 | 3시간 / 주 | 3 |A+ (4.5)|




| Editing Period | File Main Title | File Sub Title | Environment | Contents | Focus On & Main issue |
|:--------|:--------|:--------|:--------|:---------|:---------|
|~2019/04| BasicOfDataAnalysis | 1st assignment |  python / Jupyter notebook | Data pre processing<br> PCA <br> Simple data Visuallization |  |
|~2019/07| BasicOfDataAnalysis | 3rd assignment |  python / Jupyter notebook | Final Project - Free Topic | Titanic, Machine Learning From Disaster. Focused on "Study" about "Real Titanic" (Domain Knoledge Study) |

<br>

- 대표 결과물
[Final Project](https://github.com/ProtossDragoon/SJU-Subject/blob/master/2-1BasicOfDataAnalysis/3rd%20Assignment/IDA_A3_%EC%9D%B4%EC%9E%A5%ED%9B%84_18011573.ipynb)

*로딩에 많은 시간이 소요됨*


<br>
<h2>Algorithm</h2>

| Semester | Professor | Lecture Name | Language | Lecture Hours / week | Credit | GradePoint (A~D,F) |
|:--------|:--------|:--------|:--------|:---------|:---------|:---------|
| Summer |  | Algorithm  | Kor | 5hours / week | 4 | A0 |
| 2학기 | 나중채 | 알고리즘및실습  | 한국어 | 5시간 / 주 | 4 | A0 |

<br>

| Editing Period | File Main Title | File Sub Title | Environment | Contents | Focus On & Main issue |
|:--------|:--------|:--------|:--------|:---------|:---------|
|| Algorithm | 자료구조 복습 |  C / VS2019 | linked list, binary tree |  |
|~2019/09/11| Algorithm | Priority Queue |  C / VS2019 | Priority Queue and Selection/Insertion sorting | Capsulization |




<br>
<h2>Linear Algebra with Programming</h2>

| Semester | Professor | Lecture Name | Language | Lecture Hours / week | Credit | GradePoint (A~D,F) |
|:--------|:--------|:--------|:--------|:---------|:---------|:---------|
| Second |  | Linear Algebra  | Kor | 3hours / week | 3 | - |
| 2학기 | 이영렬 | 선형대수및프로그래밍 | 한국어 | 3시간 / 주 | 3 |-|

- 아파서 시험못봄 ㅠㅠ



<br>

**구조체 정의**
``` C
typedef struct matrix matrix;
struct matrix {
	int **intmatrix;
	float **floatmatrix;
	double **doublematrix;
	int type;
	int row_size;
	int col_size;
};
```

<br>
<br>


**메소드 정의**
``` C
matrix* newMatrix_square(int size, int type);
void removeMatrix_square(matrix* mat);
matrix* copyMatrix_square(matrix* mat);
// matrix 생성과 소멸과 복사 메모리 관리를 위해 사용. 이것때문에 개고생했네...

matrix* matmul_square_int(matrix *mat1, matrix* mat2);
matrix* matmul_square_double(matrix* mat1, matrix* mat2);
// matrix 곱을 반환함. mat1, mat2 는 훼손되지 않음.
 
matrix* mul_square_double(double k, matrix* mat);
// 상수 * matrix 곱을 반환함. mat 는 훼손되지 않음.

int det_square_int(matrix* mat);
double det_square_double(matrix* mat);
// determinant(행렬식) 를 [cofactor 을 이용하여] 구할때 사용. 기존 mat 은 훼손되지 않음.

matrix* transposeMatrix_square(matrix* mat);
// transpose matrix (전치행렬) 을 만들 때 사용. 기존 mat 은 훼손되지 않음.

matrix* adjugateMatrix_square_double(matrix* mat);
// adjugate matrix (수반행렬) 을 만들 때 사용. 기존 mat 은 훼손되지 않음.

matrix* inverseMatrix_square_double(matrix* mat);
// inverse matrix (역행렬) 을 [determine, adjugate matrix 를 이용하여] 만들 때 사용. 기존 mat 은 훼손되지 않음.

matrix* select_square(matrix* mat, int row, int col);
// cofactor 을 만들 때 사용. 특정 row 와 특정 col 을 제거한 matrix 를 새로 만들어서 반환함.

void printMatirx(matrix* mat);
// matrix 구조체를 print 할 때 사용
```



<br>
<h2>Computer Organization And Design</h2>

| Semester | Professor | Lecture Name | Language | Lecture Hours / week | Credit | GradePoint (A~D,F) |
|:--------|:--------|:--------|:--------|:---------|:---------|:---------|
| Second | Gi-Ho Park | Computer Structure  | Kor | 3hours / week | 3 | B+ |
| 2학기 | 박기호 | 컴퓨터구조 | 한국어 | 3시간 / 주 | 3 | B+ |

<br>

| Editing Period | File Main Title | File Sub Title | Environment | Contents | Focus On & Main issue |
|:--------|:--------|:--------|:--------|:---------|:---------|
| 1/4 | Computer Organization ... | mars | Assembly / Mars | understand ISA with Assembly | program pointer, stack pointer 로 재귀함수 구현 등 |
| 2/4 | Computer Organization ... | cahcesim |  C / VS2019 | Cahce simulator |  |
| 3/4 | Computer Organization ... | mipscpu |  C / VS2019 | cpu datapath | make cpu datapath with capsulized function |



<br>

<h1>Grade 3 (2020)</h1>

<h2>ProblemSolvingAndLAB C++</h2>

| Semester | Professor | Lecture Name | Language | Lecture Hours / week | Credit | GradePoint (A~D,F) |
|:--------|:--------|:--------|:--------|:---------|:---------|:---------|
| First | Yong-Hak Ahn | ProblemSolving&LAB C++ | Kor | 3hours / week | 3 | |
| 1학기 | 안용학 | 문제해결및실습 C++ | 한국어 | 3시간 / 주 | 3 |  |

<br>

| Editing Period | File Main Title | File Sub Title | Environment | Contents | Focus On & Main issue |
|:--------|:--------|:--------|:--------|:---------|:---------|
|         |        |          |         |          |          |
