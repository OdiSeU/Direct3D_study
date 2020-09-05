인덱스 버퍼
  - 정점 버퍼에 들어간 순서인 인덱스를 이용하여 삼각형을 구성하는 버퍼

인덱스 버퍼를 이용한 정점 렌더링 순서
  1. 정점과 인덱스 선언
  2. 정점 버퍼 생성 및 정점 입력
  3. 인덱스 버퍼 생성 및 인덱스 입력
  4. 인덱스를 이용한 출력

큐브 만들기
  인덱스는 WORD형으로 나열하며 삼각형은 시계방향(CW)으로 정점의 인덱스를 구성

인덱스 버퍼 생성
  -  lpD3dDevice->CreateIndexBuffer(sizeof(idxArr), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &lpIdxBuffer, NULL);

인덱스 버퍼에 인덱스 입력
  - lpIdxBuffer->Lock(0, sizeof(idxArr), &pIdxArr, 0);

렌더링 상태 옵션 변경
  - lpD3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

인덱스를 이용한 최종 출력
  -  lpD3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 6 * 2);