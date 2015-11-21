#include "cidade.hpp"

int Cidade::getRecursoNecessario() { return this->recursoNecessario; }

void Cidade::consumirCarga()
{
	this->setCarga(0);
}
