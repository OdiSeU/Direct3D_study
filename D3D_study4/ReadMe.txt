CUSTOMVERTEX 구조체 정의
struct CUSTOMVERTEX
{
    float x, y, z, rhw;
    DWORD color;
}
+) RHW
정점 포맷에서 RHW의 설정은 현재의 정점을 2D 좌표처럼 사용하는 것을 말한다.
RHW가 설정되면 현재의 정점 좌표가 3D 변환인 월드, 뷰, 프로젝션 변환이 적용된 최종 좌표이므로 
x, y 좌표만을 참조하여 그대로 화면에 출력하게 된다. 일반적으로 w의 값은 1.0f로 고정하여 사용한다.

3D 공간을 이루는 것
정점 -> 삼각형 -> 매쉬

도형을 구성하는 정점을 시계 방향(CW)으로 넣어준다. (법선 벡터 때문)
반시계 방향(CCW)으로 할 경우 컬링되어 출려에서 제외된다.

정점 버퍼 생성
HRESULT CreateVertexBuffer(-,-,-,-,-,-);

메모리 사용을 위한 메모리 잠금
lpD3dDevice->Lock(-,-,-,-);

메모리 복사
memcpy(-,-,-);

메모리 잠금 해제
lpD3dDevice->Unlock();

정점 출력
HRESULT DrawPrimitive(-,-,-);

그리기 방식
D3DPT_POINTLIST 점 단위로 출력
D3DPT_LINELIST 선 단위로 출력
D3DPT_LINESTRIP 연결된 선분 출력
D3DPT_TRIANGLELIST 삼각형 단위로 출력
D3DPT_TRIANGLESTRIP 연결된 삼각형 출력
D3DPT_TRIANGLEFAN 하나의 정점을 공유하는 삼각형 출력