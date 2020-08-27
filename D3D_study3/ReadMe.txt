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

벡터의 단위 벡터(단위 벡터(n) : 크기가 1인 벡터)
  - D3DXVec3Normalize(&vResult, &v4);

벡터의 내적 ( a·b = |a| * |b| * cosθ )
  -vDot = D3DXVec3Dot(&v1, &v2);

벡터의 내적을 이용해 벡터 간 사이각의 코사인 값 구하기
 - cosθ = a·b / |a| * |b|

벡터의 외적 ( a×b = n * |a| * |b| * sinθ )
  두 벡터가 이루는 평면의 수직 벡터
  - D3DXVec3Cross(&vResult, &v1, &v2);
