using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Core)

// ----- CLASS DECLARATIONS -----
class Comport;
// ------------------------------

// ---- COMPORT DECLARATIONS ----
class Comport
{

	private:

		HANDLE hPort;

	public:

		Comport(const Containers::String& sPort = Containers::String(), unsigned uSpeed = 9600);
		~Comport(void);

		bool Open(const Containers::String& sPort, unsigned uSpeed = 9600);
		void Close(void);
		bool Opened(void) const;
		bool Closed(void) const;
		unsigned WriteString(const Containers::String& sStr);
		Containers::String ReadString(char cStop = TEXT('\n'));

		template<typename tnData> unsigned WriteData(const tnData& tData);
		template<typename tnData> unsigned ReadData(tnData& tData);

};
// ------------------------------

KUSZKAPI_NAMESPACE_END
