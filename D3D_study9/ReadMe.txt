행렬 변환
  - S R T  ( Scale, Rotate, Translate )

이동, 회전, 크기 행렬 변환 함수
  - D3DXMatrixTranslation();
  - D3DXMatrixScaling();
  - D3DXToDegree();
  - D3DXToRadian();
  - D3DXMatrixRotationX();
  - D3DXMatrixRotationY();
  - D3DXMatrixRotationZ();
  - D3DXMatrixRotationAxis();
  - D3DXMatrixRotationYawPitchRoll();

쿼터니온 함수 (회전)
  - D3DXQuaternionRotationMatrix();
  - D3DXQuaternionRotationAxis();
  - D3DXQuaternionRotationYawPitchRoll();
  - D3DXMatrixRotationQuaternion();
  - D3DXQuaternionNormalize();

키보드 입력 체크
  - if(GetAsyncKeyState('A') < 0)