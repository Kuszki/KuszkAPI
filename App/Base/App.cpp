using namespace KuszkAPI::Application;

KuszkAPI::Application::App::App(void) : tRunTime(true), dRunDate(true) {}

KuszkAPI::Application::App::~App(void) {}

DateTime::Time KuszkAPI::Application::App::GetRunTime(void) const
{
      return tRunTime;
}

DateTime::Date KuszkAPI::Application::App::GetRunDate(void) const
{
      return dRunDate;
}
