#pragma once

#include "vertagt_aktion.h"
#include <list>

namespace vertagt
{
	template <class T>
	class VListe
	{
	private:
		std::list<T> p_objekte;
		std::list<std::unique_ptr<VAktion<T>>> p_aktionen;

	public:
		// Typdefinitionen
		using iterator = typename std::list<T>::iterator;
		using const_iterator = typename std::list<T>::const_iterator;

		// Konstruktoren
		VListe() = ...; // Benötigt man einen Standardkonstruktor?
		// Destruktor
		~VListe()
		{
			vAktualisieren();
			p_objekte.clear();
		}

		void clear()
		{
			...
		}

		// Lesefunktionen
		const_iterator begin() const
		{
			return p_objekte.begin();
		}
		const_iterator end() const
		{
			...
		}
		iterator begin()
		{
			return p_objekte.begin();
		}
		iterator end()
		{
			...
		}
		bool empty() const
		{
			...
		}

		// Schreibfunktionen
		void push_back(T obj)
		{
			// Aktionselement für PushBack auf Liste erzeugen
			p_aktionen.push_back(...);
		}

		void push_front(T obj)
		{
			// Aktionselement für PushBack auf Liste erzeugen
			...
		}

		void erase(iterator it)
		{
			// Aktionselement für PushBack auf Liste erzeugen (hier Iterator statt Objekt !)
			...
		}

		// Änderungen auf Objektliste übertragen
		void vAktualisieren()
		{
			// Änderungen auf Objektliste übertragen
			for (auto& pAktion : p_aktionen)
			{
				// Aktion ausführen
				...
			}
			// Aktionsliste löschen
			...
		}
	};
} // namespace vertagt
