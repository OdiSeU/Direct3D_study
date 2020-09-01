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

월드, 뷰, 투영 행렬의 설정 함수
  - SetTransform( , );

뷰 변환 행렬 함수
  - D3DXMatrixLookAtLH( , , , );

투영 변환 행렬 함수
  - D3DXMatrixPerspectiveFovRH( , , , , );