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
	D3DXMatrixIdentity(&matIdentity);	//������� �Է�

	//��� �ʱ�ȭ
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matMatrix(i, j) = float(i * 4 + j + 1);
		}
	}

	// ����� ��
	D3DXMatrixMultiply(&matResult, &matMatrix, &matIdentity);
	printMatrix(matResult);
	// ����� ��ġ���
	D3DXMatrixTranspose(&matResult, &matMatrix);
	printMatrix(matResult);
	// ȸ�� ���
	D3DXMatrixRotationX(&matResult, D3DXToRadian(90));
	printMatrix(matResult);
	// ����� �����
	D3DXMatrixInverse(&matResult, NULL, &matResult);
	printMatrix(matResult);
	// �̵� ���
	D3DXMatrixTranslation(&matResult, D3DXToRadian(90), D3DXToRadian(90), D3DXToRadian(90));
	printMatrix(matResult);
	// ũ�� ���
	D3DXMatrixScaling(&matResult, 2, 2, 2);
	printMatrix(matResult);



	return 0;
}