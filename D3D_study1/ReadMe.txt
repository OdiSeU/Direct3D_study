WinAPI에 Direct3D 탑재
Direct3DCreate9(-);
g_d3d->CreateDevice(-,-,-,-,-,-);

V/C++ - 포함 디렉터리, 라이브러리 디렉터리 경로 설정
링커 - 입력 - 추가 종속성 Direct3D 라이브러리 추가

전역변수 선언
LPDIRECT3D9 g_d3d;
LPDIRECT3DDEVICE g_d3dDevice;

게임루프 구현
init();
while(!end)
{
    update();
    render();
}
cleanup();

Direct3D 화면 출력
g_d3dDevice->BeginScene();
//Rendering here
g_d3dDevice->EndScene();

Direct3D 해제
g_d3d->Release();
g_d3dDevice->Release();

백버퍼 지우기
g_d3dDeivce->Clear(-,-,-,-,-,-);