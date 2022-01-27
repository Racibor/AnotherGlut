#include "Anim8torSupport.h"

void Anim8torSupport::draw(struct Anim8orObject* obj) {
	// OpenGL 1.1+
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	//glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	// Dla ka�dej siatki sk�adowej (mesh):
	for (int m = 0; m < obj->nMeshes; m++) {
		// Kolor ka�dego mesha jest (dla uproszczenia) kolorem
		// pierwszego z materia��w dla niego zdefiniowanych:
		glColor4fv(obj->meshes[m]->materials[0].diffuse);
		// Tabela z punktami:
		glVertexPointer(3, GL_FLOAT, 0, obj->meshes[m]->coordinates);
		// Tabela z normalnymi:
		glNormalPointer(GL_FLOAT, 0, obj->meshes[m]->normals);
		// Tabela ze wsp�rz�dnymi tekstur:
		//glTexCoordPointer(2, GL_FLOAT, 0, obj->meshes[m]->texcoords);
		// Narysowanie kszta�tu korzystaj�c z tabeli indeks�w:
		glDrawElements(GL_TRIANGLES, obj->meshes[m]->nIndices, GL_UNSIGNED_INT, obj->meshes[m]->indices);
	}

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	//glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}

void Anim8torSupport::drawTex(Anim8orObject* obj, int tex_id)
{
	if(tex_id != -1)
		glBindTexture(GL_TEXTURE_2D, tex_id);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	// Dla ka�dej siatki sk�adowej (mesh):
	for (int m = 0; m < obj->nMeshes; m++) {
		// Kolor ka�dego mesha jest (dla uproszczenia) kolorem
		// pierwszego z materia��w dla niego zdefiniowanych:
		glColor4fv(obj->meshes[m]->materials[0].diffuse);
		// Tabela z punktami:
		glVertexPointer(3, GL_FLOAT, 0, obj->meshes[m]->coordinates);
		// Tabela z normalnymi:
		glNormalPointer(GL_FLOAT, 0, obj->meshes[m]->normals);
		// Tabela ze wsp�rz�dnymi tekstur:
		glTexCoordPointer(2, GL_FLOAT, 0, obj->meshes[m]->texcoords);
		// Narysowanie kszta�tu korzystaj�c z tabeli indeks�w:
		glDrawElements(GL_TRIANGLES, obj->meshes[m]->nIndices, GL_UNSIGNED_INT, obj->meshes[m]->indices);
	}

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);


}
