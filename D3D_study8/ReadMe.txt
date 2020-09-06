D3DX에서 제공하는 도형
  - 박스, 원기둥, 구, 주전자, 텍스트, 토러스, 폴리건
  - 3D의 도형은 메쉬로 다룬다. (LPD3DXMESH)
  - 헤더 : d3dx9shape.h, 라이브러리 : d3dx9.lib

박스 생성 함수
  - D3DXCreateBox( lpD3dDevice, 2.0f, 2.0f, 2.0f, lpBoxMesh, NULL );

구 생성 함수
  - D3DXCreateSphere( lpD3dDevice, 3.0f, 30, 10, lpSphereMesh, NULL );

주전자 생성 함수
  - D3DXCreateTeapot( lpD3dDevice, lpTeapotMesh, NULL );

원기둥 생성 함수
  - D3DXCreateCylinder( lpD3dDevice, 2.0f, 2.0f, 5.0f, 30, 10, lpCylinderMesh, NULL);

도형 출력 함수
  - lpBoxMesh->DrawSubset(0);