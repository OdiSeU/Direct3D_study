#include "Cube.h"

struct CUSTOMVERTEX
{
    D3DXVECTOR3 position;
    DWORD color;
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)

void Cube::onIinit(LPDIRECT3DDEVICE9 lpD3dDevice)
{
    this->lpD3dDevice = lpD3dDevice;

    CUSTOMVERTEX vtxArr[] = {
        { D3DXVECTOR3(-1.0f, 1.0f,  1.0f) ,  D3DCOLOR_RGBA(255, 0, 255, 255) },
        { D3DXVECTOR3(1.0f, 1.0f,  1.0f)  , D3DCOLOR_RGBA(0, 255, 0, 255) },
        { D3DXVECTOR3(1.0f, 1.0f, -1.0f)  , D3DCOLOR_RGBA(0, 0, 255, 255) },
        { D3DXVECTOR3(-1.0f, 1.0f, -1.0f)  , D3DCOLOR_RGBA(255, 255, 0, 255) },

        { D3DXVECTOR3(-1.0f, -1.0f,  1.0f) , D3DCOLOR_RGBA(255, 0, 0, 255) },
        { D3DXVECTOR3(1.0f, -1.0f,  1.0f) , D3DCOLOR_RGBA(0, 255, 10, 255) },
        { D3DXVECTOR3(1.0f, -1.0f, -1.0f) , D3DCOLOR_RGBA(0, 0, 255, 255) },
        { D3DXVECTOR3(-1.0f, -1.0f, -1.0f) , D3DCOLOR_RGBA(255, 0, 0, 255) }
    };

    WORD idxArr[] =
    {
            0, 1, 2,
            0, 2, 3,
            4, 6, 5,
            4, 7, 6,
            0, 3, 7,
            0, 7, 4,
            1, 5, 6,
            1, 6, 2,
            3, 2, 6,
            3, 6, 7,
            0, 4, 5,
            0, 5, 1
    };

    lpD3dDevice->CreateVertexBuffer(sizeof(vtxArr), 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &lpVtxBuffer, NULL);

    void* pVtxArr;
    lpVtxBuffer->Lock(0, sizeof(vtxArr), &pVtxArr, 0);
    memcpy(pVtxArr, vtxArr, sizeof(vtxArr));
    lpVtxBuffer->Unlock();

    lpD3dDevice->CreateIndexBuffer(sizeof(idxArr), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &lpIdxBuffer, NULL);

    void* pIdxArr;
    lpIdxBuffer->Lock(0, sizeof(idxArr), &pIdxArr, 0);
    memcpy(pIdxArr, idxArr, sizeof(idxArr));
    lpIdxBuffer->Unlock();

}
void Cube::onRender()
{
    lpD3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
    lpD3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
    D3DXMATRIX matWorld;
    D3DXMatrixIdentity(&matWorld);
    lpD3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

    lpD3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
    lpD3dDevice->SetStreamSource(0, lpVtxBuffer, 0, sizeof(CUSTOMVERTEX));
    lpD3dDevice->SetIndices(lpIdxBuffer);
    lpD3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
    lpD3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 6 * 2); // sizeof( Indices ) / sizeof(WORD) / 3

    lpD3dDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
    lpD3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
}
void Cube::onRelease()
{
    if (lpVtxBuffer != NULL)
        lpVtxBuffer->Release();

    if (lpIdxBuffer != NULL)
        lpIdxBuffer->Release();
}

Cube::Cube()
{

}
Cube::~Cube()
{

}