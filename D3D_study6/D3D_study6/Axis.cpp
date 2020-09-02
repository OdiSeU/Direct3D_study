#include "Axis.h"

struct CUSTOMVERTEX
{
    FLOAT x, y, z;
    DWORD color; 
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)

void Axis::onInit(LPDIRECT3DDEVICE9 lpd3dDevice)
{
	this->lpD3dDevice = lpd3dDevice;

	CUSTOMVERTEX vtxArr[] =
	{
		{ -3.0f,  0.0f, 0.0f, D3DCOLOR_RGBA(255, 0, 0, 255) },  // x รเ
		{ 3.0f,  0.0f, 0.0f, D3DCOLOR_RGBA(255, 0, 0, 255) },

		{ 0.0f,  -3.0f, 0.0f, D3DCOLOR_RGBA(0, 255, 0, 255) }, // y รเ
		{ 0.0f,  3.0f, 0.0f, D3DCOLOR_RGBA(0, 255, 0, 255) },

		{ 0.0f,  0.0f, -3.0f, D3DCOLOR_RGBA(0, 255, 255, 255) }, // z รเ
		{ 0.0f,  0.0f, 3.0f, D3DCOLOR_RGBA(0, 255, 255, 255) }
	};

	lpD3dDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &lpVtxBuffer, NULL);

	void* pVtxArr;
	lpVtxBuffer->Lock(0, sizeof(vtxArr), &pVtxArr, 0);
	memcpy(pVtxArr, vtxArr, sizeof(vtxArr));
	lpVtxBuffer->Unlock();
}

void Axis::onRender()
{
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	lpD3dDevice->SetRenderState(D3DRS_LIGHTING, false);
	lpD3dDevice->SetStreamSource(0, lpVtxBuffer, 0, sizeof(CUSTOMVERTEX));
	lpD3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	lpD3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	lpD3dDevice->DrawPrimitive(D3DPT_LINELIST, 0, 3);
	lpD3dDevice->SetRenderState(D3DRS_LIGHTING, true);
}

void Axis::onRelease()
{
	if (lpVtxBuffer != NULL)
		lpVtxBuffer->Release();
}

Axis::Axis()
{

}

Axis::~Axis()
{

}