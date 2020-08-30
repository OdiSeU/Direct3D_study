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
	D3DXVECTOR3 vResult, vector = {1.0f, 0.0f, 1.0f};
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
	D3DXMatrixTranslation(&matResult, 10, 10, 10);
	printMatrix(matResult);
	// ũ�� ���
	D3DXMatrixScaling(&matResult, 2, 2, 2);
	printMatrix(matResult);
	// XYZ �� ��� ȸ�� ���
	D3DXMatrixRotationYawPitchRoll(&matResult, D3DXToRadian(90), D3DXToRadian(90), D3DXToRadian(90));
	printMatrix(matResult);
	// ������ ���� �������� ȸ���ϴ� ȸ�� ���
	D3DXMatrixRotationAxis(&matResult, &vector, D3DXToRadian(90));
	printMatrix(matResult);
	// ���ʹϿ�
	D3DXQUATERNION quat;
	D3DXMATRIX matRotation;
	D3DXMatrixRotationX(&matRotation, D3DXToRadian(90));
	// ȸ�� ����� ���ʹϿ����� ����� �Լ�
	D3DXQuaternionRotationMatrix(&quat, &matRotation);
	printf("x : %f , y : %f, z : %f, z : %f\n", quat.x, quat.y, quat.z, quat.w);
	// yaw, pitch, roll�� ���� ���ʹϿ��� ����� �Լ�
	D3DXQuaternionRotationYawPitchRoll(&quat, D3DXToRadian(90), D3DXToRadian(90), D3DXToRadian(90));
	printf("x : %f , y : %f, z : %f, z : %f\n", quat.x, quat.y, quat.z, quat.w);
	// ������ �࿡ ���ؼ� ȸ���� ���ʹϿ��� ���ϴ� �Լ�
	D3DXQuaternionRotationAxis(&quat, &vector, D3DXToRadian(90));
	printf("x : %f , y : %f, z : %f, z : %f\n", quat.x, quat.y, quat.z, quat.w);
	// ���ʹϿ����κ��� ȸ�� ����� ���ϴ� �Լ�
	D3DXMatrixRotationQuaternion(&matResult, &quat);
	printMatrix(matResult);
	// ���̰� 1�� ���ʹϿ��� ���ϴ� �Լ�
	D3DXQuaternionNormalize(&quat, &quat);
	printf("x : %f , y : %f, z : %f, z : %f\n", quat.x, quat.y, quat.z, quat.w);

	return 0;
}