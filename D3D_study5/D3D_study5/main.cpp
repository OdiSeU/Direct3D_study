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
	D3DXMatrixTranslation(&matResult, 10, 10, 10);
	printMatrix(matResult);
	// 크기 행렬
	D3DXMatrixScaling(&matResult, 2, 2, 2);
	printMatrix(matResult);
	// XYZ 축 모두 회전 행렬
	D3DXMatrixRotationYawPitchRoll(&matResult, D3DXToRadian(90), D3DXToRadian(90), D3DXToRadian(90));
	printMatrix(matResult);
	// 임의의 축을 기준으로 회전하는 회전 행렬
	D3DXMatrixRotationAxis(&matResult, &vector, D3DXToRadian(90));
	printMatrix(matResult);
	// 쿼터니온
	D3DXQUATERNION quat;
	D3DXMATRIX matRotation;
	D3DXMatrixRotationX(&matRotation, D3DXToRadian(90));
	// 회전 행렬을 쿼터니온으로 만드는 함수
	D3DXQuaternionRotationMatrix(&quat, &matRotation);
	printf("x : %f , y : %f, z : %f, z : %f\n", quat.x, quat.y, quat.z, quat.w);
	// yaw, pitch, roll에 의한 쿼터니온을 만드는 함수
	D3DXQuaternionRotationYawPitchRoll(&quat, D3DXToRadian(90), D3DXToRadian(90), D3DXToRadian(90));
	printf("x : %f , y : %f, z : %f, z : %f\n", quat.x, quat.y, quat.z, quat.w);
	// 임의의 축에 대해서 회전한 쿼터니온을 구하는 함수
	D3DXQuaternionRotationAxis(&quat, &vector, D3DXToRadian(90));
	printf("x : %f , y : %f, z : %f, z : %f\n", quat.x, quat.y, quat.z, quat.w);
	// 쿼터니온으로부터 회전 행렬을 구하는 함수
	D3DXMatrixRotationQuaternion(&matResult, &quat);
	printMatrix(matResult);
	// 길이가 1인 쿼터니온을 구하는 함수
	D3DXQuaternionNormalize(&quat, &quat);
	printf("x : %f , y : %f, z : %f, z : %f\n", quat.x, quat.y, quat.z, quat.w);

	return 0;
}