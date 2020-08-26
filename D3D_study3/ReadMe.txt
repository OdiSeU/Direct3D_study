헤더 : D3DX9Math.h, 라이브러리 : d3dx9.lib

벡터 구조체
  - D3DVECTOR
  - D3DXVECTOR3

벡터의 덧셈
  - v3 = v1 + v2;
  - D3DXVec3Add(&v3, &v1, &v2);

벡터의 뺄셈
  - v3 = v4 - v1;
  - D3DXVec3Substract(&v3, &v4, &v1);

벡터의 크기
  - length = D3DXVec3Length(&v3);

벡터의 크기의 제곱
  - length = D3DXVec3Length(&v3);

벡터의 크기 변환
  - D3DXVec3Scale(&vResult, &vResult, 2.0f);

벡터의 단위 벡터(단위 벡터 : 크기가 1인 벡터)
  - D3DXVec3Normalize(&vResult, &v4);