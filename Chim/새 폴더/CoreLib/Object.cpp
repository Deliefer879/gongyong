#include "Object.h"
#include "CameraManger.h"

void Object::SetMatrix()
{
	Matrix matScale, matTrans, matRot, matWorld;
	matScale.Scale(scale);
	matRot.RotateZ(rotation.z);
	matTrans.Translate(position);

	matWorld = matScale * matRot * matTrans;

	renderer.SetCBData(matWorld, MainCamera->viewMatrix, MainCamera->orthoprojMatrix);
}

void Object::SetSprite(AnimationInfo info)
{
	renderer.SetResource(info.animFileName, info.shaFileName);
}

bool Object::Init(ID3D11Device* pDevice)
{
	renderer.Init(pDevice);
	renderer.DisableBackfaceCulling(pDevice);

	return true;
}
bool Object::Frame()
{
	if (!isRender)
		return true;

	renderer.Frame();

	return true;
}
bool Object::Render(ID3D11DeviceContext* pContext)
{
	if(!isRender) 
		return true;

	SetMatrix();
	renderer.Render(pContext);

	return true;
}
bool Object::Release()
{
	renderer.Release();

	return true;
}