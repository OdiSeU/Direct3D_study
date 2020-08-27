#include <iostream>
#include <d3dx9math.h>

int main()
{
	D3DXVECTOR3 v1(0.0f, 3.0f, 0.0f);
	D3DXVECTOR3 v2(3.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vResult;
	D3DXVECTOR3 v4(3.0f, 3.0f, 0.0f);
	float length;

	// ∫§≈Õ¿« µ´º¿
	vResult = v1 + v2;
	printf("∫§≈Õ µ°º¿ : %f %f %f \n", vResult.x, vResult.y, vResult.z);

	D3DXVec3Add(&vResult, &v1, &v2);
	printf("∫§≈Õ µ°º¿ : %f %f %f \n", vResult.x, vResult.y, vResult.z);

	// ∫§≈Õ¿« ª¨º¿
	vResult = v4 - v1;
	printf("∫§≈Õ ª¨º¿ : %f %f %f \n", vResult.x, vResult.y, vResult.z);

	D3DXVec3Subtract(&vResult, &v4, &v1);
	printf("∫§≈Õ ª¨º¿ : %f %f %f \n", vResult.x, vResult.y, vResult.z);

	// ∫§≈Õ¿« ≈©±‚
	length = D3DXVec3Length(&v4);
	printf("∫§≈Õ¿« ≈©±‚ : %f \n", length);

	// ∫§≈Õ¿« ≈©±‚¿« ¡¶∞ˆ
	length = D3DXVec3LengthSq(&v4);
	printf("∫§≈Õ¿« ≈©±‚ : %f \n", length);

	// ∫§≈Õ¿« ≈©±‚ ∫Ø»Ø
	printf("±‚¡∏ ∫§≈Õ : %f %f %f \n", vResult.x, vResult.y, vResult.z);
	D3DXVec3Scale(&vResult, &vResult, 2.0f);
	printf("∫§≈ÕøÕ ¡§ºˆ ∞ˆ : %f %f %f \n", vResult.x, vResult.y, vResult.z);

	// ∫§≈Õ¿« ¥‹¿ß ∫§≈Õ
	D3DXVec3Normalize(&vResult, &v4);
	printf("∫§≈Õ¿« ¥‹¿ß ∫§≈Õ : %f %f %f \n", vResult.x, vResult.y, vResult.z);
	printf("¥‹¿ß ∫§≈Õ¿« ≈©±‚ :  %f \n", D3DXVec3Length(&vResult));

	// ∫§≈Õ¿« ≥ª¿˚
	float vDot = D3DXVec3Dot(&v1, &v2);
	printf("∫§≈Õ¿« ≥ª¿˚ :  %f \n", vDot);

	// ∫§≈Õ¿« ≥ª¿˚¿ª ¿ÃøÎ«— ∫§≈Õ ∞£ ªÁ¿Ã∞¢ ±∏«œ±‚
	float vLengthMult = D3DXVec3Length(&v1) * D3DXVec3Length(&v2);
	float vCos = vDot / vLengthMult;
	float vRadian = acos(vCos);
	float vAngle = vRadian * 180 / 3.14159265;
	printf("∫§≈Õ¿« ªÁ¿Ã∞¢ :  %f \n", vAngle);

	// ∫§≈Õ¿« ø‹¿˚
	D3DXVec3Cross(&vResult, &v1, &v2);
	printf("∫§≈Õ¿« ø‹¿˚ : %f %f %f \n", vResult.x, vResult.y, vResult.z);
	D3DXVec3Normalize(&vResult, &vResult);
	printf("ø‹¿˚¿« ¥‹¿ß ∫§≈Õ : %f %f %f \n", vResult.x, vResult.y, vResult.z);

	return 0;
}