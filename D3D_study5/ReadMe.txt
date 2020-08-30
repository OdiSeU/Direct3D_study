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
  - D3DXMatrixRotationX(&matResult, D3DXToRadian(90));
  - D3DXMatrixRotationY(&matResult, D3DXToRadian(90));
  - D3DXMatrixRotationZ(&matResult, D3DXToRadian(90));

이동행렬
  - D3DXMatrixTranslation(&matResult, D3DXToRadian(90), D3DXToRadian(90), D3DXToRadian(90));

크기 행렬
  - D3DXMatrixScaling(&matResult, 2, 2, 2);

라디안과 호도값의 변환 매크로 함수
  - D3DXToDegree( radiain );
  - D3DXToRadian( degree );

XYZ 축 모두 회전 행렬
  - D3DXMatrixRotationYawPitchRoll(&matResult, D3DXToRadian(90), D3DXToRadian(90), D3DXToRadian(90));

임의의 축을 기준으로 회전하는 회전 행렬
  - D3DXMatrixRotationAxis(&matResult, &vector, D3DXToRadian(90));

이동, 회전, 크기 행렬의 결합 순서
 Scaling -> Rotation(z->x->y) -> Translation

쿼터니온
  임의의 축을 기준으로 회전 행렬을 구해주는 수학도구
  일반 회전 행렬에 비해 계산량이 적다.
  메모리를 적게 차지한다.
  짐벌락 현상을 완전하게 해결한다.

쿼터니온 데이터구조
  - D3DXQUATERNION
  - x, y, z : 회전축, w : 회전값(라디안)
  - 반시계 방향 회전
  - 쿼터니온 연산은 우에서 좌 순서로 계산

회전 행렬을 쿼터니온으로 만드는 함수
  - D3DXQuaternionRotationMatrix(&quat, &matRotation);

yaw, pitch, roll에 의한 쿼터니온을 만드는 함수
  - D3DXQuaternionRotationYawPitchRoll(&quat, D3DXToRadian(90), D3DXToRadian(90), D3DXToRadian(90));

임의의 축에 대해서 회전한 쿼터니온을 구하는 함수
  - D3DXQuaternionRotationAxis(&quat, &vector, D3DXToRadian(90));

쿼터니온으로부터 회전 행렬을 구하는 함수
  - D3DXMatrixRotationQuaternion(&matResult, &quat);

길이가 1인 쿼터니온을 구하는 함수
  - D3DXQuaternionNormalize(&quat, &quat);