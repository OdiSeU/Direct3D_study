#include <iostream>
#include  <d3dx9math.h>

void printMatrix(D3DXMATRIX matrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%6.1f", matrix.m[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------\n");
}

int main()
{
	D3DXVECTOR3 vResult, vector = {};
	D3DXMATRIX matIdentity, matMatrix, matResult;
	D3DXMatrixIdentity(&matIdentity);	//단위행렬 입력

	//행렬 초기화
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matMatrix(i, j) = float(i * 4 + j + 1);
		}
	}

	// 행렬의 곱
	D3DXMatrixMultiply(&matResult, &matMatrix, &matIdentity);
	printMatrix(matResult);
	// 행렬의 전치행렬
	D3DXMatrixTranspose(&matResult, &matMatrix);
	printMatrix(matResult);
	// 회전 행렬
	D3DXMatrixRotationX(&matResult, D3DXToRadian(90));
	printMatrix(matResult);
	// 행렬의 역행렬
	D3DXMatrixInverse(&matResult, NULL, &matResult);
	printMatrix(matResult);
	// 이동 행렬
	D3DXMatrixTranslation(&matResult, D3DXToRadian(90), D3DXToRadian(90), D3DXToRadian(90));
	printMatrix(matResult);
	// 크기 행렬
	D3DXMatrixScaling(&matResult, 2, 2, 2);
	printMatrix(matResult);



	return 0;
}