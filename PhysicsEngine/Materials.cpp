#include "Materials.h"
//add material to
void Materials::AddMaterial(string name, PxMaterial* mat)
{
	try {
		materials[name] = mat;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

}

PxMaterial * Materials::GetMaterial(string name)
{
	return materials[name];
}
