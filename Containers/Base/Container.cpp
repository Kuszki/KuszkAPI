using namespace KuszkAPI;

KuszkAPI::Containers::Container::Container(void)
{
	uIlosc	=	0;
	uMode	=	MODE_QUEUE;
}

KuszkAPI::Containers::Container::~Container(void) {}

unsigned KuszkAPI::Containers::Container::Capacity(void) const
{
	return uIlosc;
}

bool KuszkAPI::Containers::Container::Empty(void) const
{
	return !uIlosc;
}

void KuszkAPI::Containers::Container::SetMode(unsigned uNewMode)
{
	uMode = uNewMode;
}

unsigned KuszkAPI::Containers::Container::GetMode(void) const
{
	return uMode;
}

KuszkAPI::Containers::Container::operator bool (void) const
{
	return !Empty();
}

template<typename tnData>
bool KuszkAPI::Containers::Container::Change(tnData& tOne, tnData& tTwo)
{
	if (&tOne == &tTwo) return false;

	tnData tTmp = tOne;
	tOne = tTwo;
	tTwo = tTmp;

	return true;
}

template<typename tnData>
void KuszkAPI::Containers::Container::Copy(const tnData& tSource, tnData& tDestonation)
{
	memcpy(&tDestonation, &tSource, sizeof(tnData));
}
