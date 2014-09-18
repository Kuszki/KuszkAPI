using namespace KuszkAPI;

KUSZKAPI_NAMESPACE(Containers)

// --- TEMPLATES DECLARATIONS ---
template<typename tnData> class List;
template<typename tnData> class Vector;
template<typename tnData> class Array;
template<typename tnData> class Box;
template<typename tnData, typename tnKey> class Map;
// ------------------------------

// ----- LIST DECLARATIONS ------
template<typename tnData>
class List : public Container
{
	protected:

		struct ItemData
		{
			tnData* ptData;
			ItemData* ptNext;
		};

		ItemData* ptBegin;
		ItemData* ptLast;

		tnData tAbstract;

	public:

		List(const List<tnData>& lList);
		List(const Vector<tnData>& vVector);
		List(const Array<tnData>& aArray);
		List(const tnData ptData[],
			unsigned uCount);
		List(void);
		~List(void);

		unsigned Add(const tnData& tData,
				   int iPos = LAST,
				   bool bMode = ADD_AFTER);
		unsigned Add(const tnData ptData[],
				   unsigned uCount,
				   int iPos = LAST,
				   bool bMode = ADD_AFTER);
		bool Delete(int iNumer);
		const tnData& GetData(int iNumer) const;
		unsigned Find(const tnData& tData) const;
		bool Contain(const tnData& tData) const;
		bool Change(int iOne,
				  int iTwo);
		unsigned Change(const tnData& tOld,
					 const tnData& tNew,
					 bool bAll = false);
		bool Sort(bool bGrow = true);
		bool Sort(List<tnData>* pptData[],
				unsigned uCount,
				bool bGrow = true);
		void Reverse(void);
		void Clean(void);

		tnData& operator[] (int iNumer);
		const tnData& operator[] (int iNumer) const;
		List<tnData>& operator<< (const tnData& tData);
		List<tnData>& operator>> (tnData& tData);
		bool operator== (const List<tnData>& lList) const;
		bool operator!= (const List<tnData>& lList) const;
		List<tnData> operator+ (const List<tnData>& lList) const;
		List<tnData>& operator+= (const List<tnData>& lList);
		List<tnData>& operator= (const List<tnData>& lList);

};
// ------------------------------

// ---- VECTOR DECLARATIONS -----
template<typename tnData>
class Vector : public Container
{

	protected:

		tnData* ptBegin;

		unsigned uDataSize;

		tnData tAbstract;

	public:

		template<typename tnPrev> Vector(const Vector<tnPrev>& vVector);

		Vector(const Vector<tnData>& vVector);
		Vector(const Array<tnData>& aArray);
		Vector(const List<tnData>& lList);
		Vector(const tnData ptData[],
			  unsigned uCount);
		Vector(void);
		~Vector(void);

		unsigned Add(const tnData& tData,
				   int iPos = LAST,
				   bool bMode = ADD_AFTER);
		unsigned Add(const tnData ptData[],
				   unsigned uCount,
				   int iPos = LAST,
				   bool bMode = ADD_AFTER);
		bool Delete(int iNumer);
		const tnData& GetData(int iNumer) const;
		const tnData* GetBegin(void) const;
		const tnData* GetEnd(void) const;
		unsigned Find(const tnData& tData) const;
		bool Contain(const tnData& tData) const;
		bool Change(unsigned uOne,
				  unsigned uTwo);
		unsigned Change(const tnData& tOld,
					 const tnData& tNew,
					 bool bAll = false);
		bool Sort(bool bGrow = true);
		bool Sort(Vector<tnData>* pptData[],
				unsigned uCount,
				bool bGrow = true);
		void Reverse(void);
		void Clean(void);

		tnData& operator[] (int iNumer);
		const tnData& operator[] (int iNumer) const;
		Vector<tnData>& operator<< (const tnData& tData);
		Vector<tnData>& operator>> (tnData& tData);
		bool operator== (const Vector<tnData>& vVector) const;
		bool operator!= (const Vector<tnData>& vVector) const;
		Vector<tnData> operator+ (const Vector<tnData>& vVector) const;
		Vector<tnData>& operator+= (const Vector<tnData>& vVector);
		Vector<tnData>& operator= (const Vector<tnData>& vVector);

		static void Sort(tnData ptData[],
					  unsigned uCount,
					  bool bGrow);
		static void Reverse(tnData ptData[],
						unsigned uCount);
		static unsigned Change(tnData ptData[],
						   unsigned uSize,
						   const tnData& tOld,
						   const tnData& tNew,
						   bool bAll = false);

};
// ------------------------------

// ----- ARRAY DECLARATIONS -----
template<typename tnData>
class Array : public Container
{
	protected:

		tnData* ptBegin;

		unsigned uDataSize;

		tnData tAbstract;

	public:

		template<typename tnPrev> Array(const KuszkAPI::Containers::Array<tnPrev>& aArray);

		Array(const Array<tnData>& aArray);
		Array(const Vector<tnData>& vVector);
		Array(const List<tnData>& lList);
		Array(const tnData ptData[],
			 unsigned uCount);
		Array(void);
		~Array(void);

		unsigned Add(const tnData& tData,
				   int iPos = LAST,
				   bool bMode = ADD_AFTER);
		unsigned Add(const tnData ptData[],
				   unsigned uCount,
				   int iPos = LAST,
				   bool bMode = ADD_AFTER);
		bool Delete(int iNumer);
		const tnData& GetData(int iNumer) const;
		const tnData* GetBegin(void) const;
		const tnData* GetEnd(void) const;
		void Clean(void);

		tnData& operator[] (int iNumer);
		const tnData& operator[] (int iNumer) const;
		Array<tnData>& operator<< (const tnData& tData);
		Array<tnData>& operator>> (tnData& tData);
		Array<tnData> operator+ (const Array<tnData>& aArray) const;
		Array<tnData>& operator+= (const Array<tnData>& aArray);
		Array<tnData>& operator= (const Array<tnData>& aArray);

};
// ------------------------------

// ------ BOX DECLARATIONS ------
template<typename tnData>
class Box
{

	protected:

		    Vector<tnData*> vPointers;

		    unsigned uIlosc;

	public:

		Box(const Box<tnData>& bBox);
		Box(void);
		~Box(void);

		unsigned Add(const tnData& tData,
				   int iPos = LAST,
				   bool bMode = ADD_AFTER);
		unsigned Add(tnData* ptData,
				   int iPos = LAST,
				   bool bMode = ADD_AFTER);
		bool Delete(int iNumer);
		const tnData& GetData(int iNumer) const;
		unsigned Capacity(void) const;
		bool Empty(void) const;
		void Clean(void);

		tnData& operator[] (int iNumer);
		const tnData& operator[] (int iNumer) const;
		Box<tnData>& operator= (const Box<tnData>& bBox);

};
// ------------------------------

// ------ MAP DECLARATIONS ------
template<typename tnData, typename tnKey>
class Map
{
	protected:

		Box<tnData> bData;
		List<tnKey> lKey;

		unsigned uIlosc;

	public:

		Map(const Map<tnData, tnKey>& mMap);
		Map(void);
		~Map(void);

		unsigned Add(const tnData& tData,
				   const tnKey& tKey);
		unsigned Add(tnData* ptData,
				   const tnKey& tKey);
		bool Delete(const tnKey& tKey);
		const tnData& GetData(const tnKey& tKey) const;
		void SetKey(const tnKey& tKey,
				  int iNumer);
		const tnKey& GetKey(int iNumer) const;
		void SetDataByInt(const tnData& tData,
					   int iNumer);
		tnData& GetDataByInt(int iNumer);
		unsigned Capacity(void) const;
		bool Allow(const tnKey& tKey) const;
		bool Contain(const tnKey& tKey) const;
		void Clean(void);

		tnData& operator[] (const tnKey& tKey);
		const tnData& operator[] (const tnKey& tKey) const;
		Map<tnData, tnKey>& operator= (const Map<tnData, tnKey>& mMap);

};
// ------------------------------

KUSZKAPI_NAMESPACE_END
