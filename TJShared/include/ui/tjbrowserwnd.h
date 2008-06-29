#ifndef _TJBROWSERWND_H
#define _TJBROWSERWND_H

namespace tj {
	namespace shared {
		class BrowserWnd;

		class EXPORTED BrowserToolbarWnd: public ToolbarWnd {
			public:
				BrowserToolbarWnd(BrowserWnd* browser);
				virtual ~BrowserToolbarWnd();
				virtual void Paint(graphics::Graphics& g, ref<Theme> theme);
				virtual void SetURL(std::wstring url);
				virtual void Layout();

			protected:
				virtual void OnCommand(int c);
				virtual void OnCommand(ref<ToolbarItem> ti);
				virtual LRESULT Message(UINT msg, WPARAM wp, LPARAM lp);

				BrowserWnd* _browser;
				ref<EditWnd> _url;

				enum Commands {
					CmdNone = 0,
					CmdBack,
					CmdForward,
					CmdStop,
					CmdReload,
					CmdGo,
				};
		};

		class BrowserSink;

		class EXPORTED BrowserWnd: public ChildWnd {
			friend class BrowserSink;

			public:
				BrowserWnd(std::wstring title);
				virtual ~BrowserWnd();
				virtual void Paint(graphics::Graphics& g, ref<Theme> theme);
				void Hide(bool t);
				void Navigate(const std::wstring& url);
				virtual void Layout();
				virtual void SetShowToolbar(bool t);
				virtual void Back();
				virtual void Forward();
				virtual void Stop();
				virtual void Reload();

			protected:
				virtual void OnSize(const Area& newSize);

				void* _ax;
				ref<BrowserToolbarWnd> _tools;
				BrowserSink* _sink;
		};
	}
}

#endif