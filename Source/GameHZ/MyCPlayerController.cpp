 #include "GameHZ.h"
#include "MyCPlayerController.h"




void AMyCPlayerController::LogginInGame_Or_Registration(FString login, FString password, bool RA, FString url)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

	JsonObject->SetStringField(TEXT("login"), login); //*FString::Printf(TEXT("%s"), *SomeFStringVariable));
	JsonObject->SetStringField(TEXT("password"), password);
	FString OutputString;

	TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);

	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();

	HttpRequest->SetVerb("POST");

	HttpRequest->SetHeader("Content-Type", "application/json");
	if (RA&&url.Equals("0"))
	{
		HttpRequest->SetURL("81.5.112.206:8080/game/registration");
	}
	else if(!RA&&url.Equals("0"))
	{
		HttpRequest->SetURL("81.5.112.206:8080/game/loggin");
	}
	else
	{
		HttpRequest->SetURL(url);
	}

	HttpRequest->SetContentAsString(OutputString);

	HttpRequest->OnProcessRequestComplete().BindUObject(this, &AMyCPlayerController::OnYourFunctionCompleted);

	HttpRequest->ProcessRequest();
}

FString AMyCPlayerController::get_id()
{
	return id;
}

int32 AMyCPlayerController::get_result()
{
	return result;
}

void AMyCPlayerController::OnYourFunctionCompleted(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	FString JsonString = Response->GetContentAsString();
	int  i;
	if (bWasSuccessful)// && Response->GetContentType() == "application/json")
	{
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());

		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonString);

		FJsonSerializer::Deserialize(JsonReader, JsonObject);

		i = JsonObject->GetIntegerField("result");

		if (i==0)
		{
			result = 0;
		}
		else if (i==1)
		{
			result = 1;
			level = JsonObject->GetIntegerField("level");
			id = JsonObject->GetStringField("id");
		}
	}
	else
	{
		if (JsonString.Equals("ошибка регистрации логина"))
		{
			result = -1;// Не Успешно зарегистрированы--такой логин уже используется
		}

		else if (JsonString.Equals("ошибка авторизации логина"))
		{
			result = -2;// Не Успешно авторизованны--неверный логин или пароль
		}

	}


}
