행렬 구조체
  - D3DMATRIX
  - D3DXMATRIX

행렬 값 접근
matMatrix(i,j)
matMatrix.m[i][j]

행렬의 곱
  - D3DXMatrixMultiply(&matResult, &mat1, &mat2);

단위행렬
 1 0 0 0
 0 1 0 0
 0 0 1 0
 0 0 0 1
  - D3DXMatrixIdentity(&matIdentity);

전치행렬 (행과 열을 바꾼행렬)
 1 2 3           1 4 7 
 4 5 6     ->   2 5 8
 7 8 9           3 6 9
  - 

역행렬 (행렬 곱의 결과가 단위 행렬인 행렬)
  - D3DXMatrixInverse(&matResult, NULL, &matMatrix);

회전행렬
  - D3DXMatrixRotationX(&matResult, 90*3.15159265/180);
  - D3DXMatrixRotationY(&matResult, 90*3.15159265/180);
  - D3DXMatrixRotationZ(&matResult, 90*3.15159265/180);