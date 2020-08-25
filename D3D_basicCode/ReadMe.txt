기본 WinAPI 창 생성 코드

단축키 관련 변수 제거
HACCEL hAccelTable;

전역변수 선언
HWND g_hWnd

메세지 루프 부분
GetMessage => PeekMessage
GetMessage는 메세지가 없을 경우 대기
PeekMessage는 메세지 없을경우 false 반환