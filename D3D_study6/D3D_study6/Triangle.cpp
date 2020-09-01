#include "Triangle.h"

void Triangle::onInit(LPDIRECT3DDEVICE9 lpD3dDevice)
{
	this->lpD3dDevice = lpD3dDevice;

	CUSTOMVERTEX vtxArr[] =
	{
		{ 150.0f,  50.0f, 0.5f, 1.0f, 0xffff0000, },
		{ 250.0f, 250.0f, 0.5f, 1.0f, 0xff00ff00, },
		{  50.0f, 250.0f, 0.5f, 1.0f, 0xff00ffff, },
	};

	lpD3dDevice->CreateVertexBuffer(
		3 * sizeof(CUSTOMVERTEX),
		0,
		D3DFVF_CUSTOMVERTEX,
		D3DPOOL_DEFAULT,
		&lpVtxBuffer,
		NULL
	);

	void* pVtxArr;
	lpVtxBuffer->Lock(0, sizeof(vtxArr), (void**)&pVtxArr, 0);
	memcpy(pVtxArr, vtxArr, sizeof(vtxArr));
	lpVtxBuffer->Unlock();
}
void Triangle::onRender()
{
	lpD3dDevice->SetStreamSource(0, lpVtxBuffer, 0, sizeof(CUSTOMVERTEX));
	lpD3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	lpD3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 1);
}
void Triangle::onRelease()
{
	if (lpVtxBuffer != NULL) lpVtxBuffer->Release();
}
Triangle::Triangle()
{

}
Triangle::~Triangle()
{

}