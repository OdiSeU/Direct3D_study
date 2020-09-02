정점 렌더링 파이프 라인
  World Transformation
  View Transformation
  Projection Transformation
  Clipping and Viewport Scaling

모델 좌표
  - 3D 물체의 기준 좌표
  - (0, 0, 0)을 기준으로 하는 정점의 좌표

월드 변환 (World Transformation)
  - 모델 좌표를 가진 물체의 정점들을 행렬변환(SRT)을 통해 렌더링 공간에 위치시키는 변환

뷰 변환 (View Transformation) ≒ 카메라
  - 월드 공간의 모든 정점을 이동 및 회전 시켜 뷰 공간으로 가져오는 변환
  - 뷰 변환 행렬 =>  V = T * Rz * Ry * Rx
     └ 스케일 없음

투영 변환 (Projection Transformation)
  - 원근 투영으로 가까운 물체와 먼 거리의 물체를 원근감 있게 하는 변환

깊이 버퍼
  - 카메라와 가장 가까운 픽셀만을 출력하기 위한 픽셀의 정보를 저장하는 기법
  - z 퍼버 설정 코드
   init() {
     d3dpp.EnableAutoDepthStencil = true;
     d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
     lpD3dDevice->SetRenderState(D3DRS_ZENABLE, true);
   }
   render() {
     lpD3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 100), 1.0f, 0);
   }

정점 렌더링 파이프라인 만들기
  - 월드 변환 행렬 설정
    lpD3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
  - 뷰 변환 행렬 설정
    D3DXMatrixLookAtLH( , , , );
    lpD3dDevice->SetTransform(D3DTS_VIEW, &matView);
  - 투영 변환 행렬 설정
    D3DXMatrixPerspectiveFowLH( , , , );
    lpD3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);

뷰포트 설정
  - 렌더링 하기 위한 화면의 크기를 설정
    D3DVIEWPORT9 vp;
    lpD3dDevice->SetViewprot(&vp);

축 만들기
  - 축은 고정이기 때문에 update 필요없따!