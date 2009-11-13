#ifndef _TJLANGUAGE_H
#define _TJLANGUAGE_H

#include "tjsharedinternal.h"
#include <deque>
#include <vector>
#include <map>

namespace tj {
	namespace shared {
		typedef String LocaleIdentifier;
		class Property;
		class Inspectable;

		class EXPORTED Language: public virtual Object {
			public:
				static const wchar_t* Get(const String& id);
				static const wchar_t* GetLiteral(const std::string& lit);
				static void Load(const String& file);
				static void LoadDirectory(const String& dir, const LocaleIdentifier& locale);
				static void GetAvailableLocales(std::deque<LocaleIdentifier>& lst);

				/** Translates menus for a window to the language **/
				#ifdef _WIN32
					static void Translate(HWND wnd);
					static void Translate(HMENU menu);
				#endif

				virtual ~Language();
				static void Clear();
				Language();
				
			protected:
				static void FindLocales(const String& dir);

				static std::vector< LocaleIdentifier > _availableLocales;
				std::map<std::string, wchar_t*> _strings;
		};
	}
}

#define TL(id) (tj::shared::Language::GetLiteral(std::string(#id)))

#endif