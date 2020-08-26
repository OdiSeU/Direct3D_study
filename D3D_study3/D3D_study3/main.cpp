#include <iostream>
#include <d3dx9math.h>

int main()
{
	D3DXVECTOR3 v1(0.0f, 3.0f, 0.0f);
	D3DXVECTOR3 v2(3.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vResult;
	D3DXVECTOR3 v4(3.0f, 3.0f, 0.0f);
	float length;

	// ������ ����
	vResult = v1 + v2;
	printf("���� ���� : %f %f %f \n", vResult.x, vResult.y, vResult.z);

	D3DXVec3Add(&vResult, &v1, &v2);
	printf("���� ���� : %f %f %f \n", vResult.x, vResult.y, vResult.z);

	// ������ ����
	vResult = v4 - v1;
	printf("���� ���� : %f %f %f \n", vResult.x, vResult.y, vResult.z);

	D3DXVec3Subtract(&vResult, &v4, &v1);
	printf("���� ���� : %f %f %f \n", vResult.x, vResult.y, vResult.z);

	// ������ ũ��
	length = D3DXVec3Length(&v4);
	printf("������ ũ�� : %f \n", length);

	// ������ ũ���� ����
	length = D3DXVec3LengthSq(&v4);
	printf("������ ũ�� : %f \n", length);

	// ������ ũ�� ��ȯ
	printf("���� ���� : %f %f %f \n", vResult.x, vResult.y, vResult.z);
	D3DXVec3Scale(&vResult, &vResult, 2.0f);
	printf("���Ϳ� ���� �� : %f %f %f \n", vResult.x, vResult.y, vResult.z);

	//������ ���� ����
	D3DXVec3Normalize(&vResult, &v4);
	printf("������ ���� ���� : %f %f %f \n", vResult.x, vResult.y, vResult.z);
	printf("���� ������ ũ�� :  %f \n", D3DXVec3Length(&vResult));


	return 0;
}