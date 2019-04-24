Action()
{

	lr_start_transaction("WeatherApi");

	web_submit_data("web_submit_data",
		"Action=https://samples.openweathermap.org/data/2.5/weather?q=London,uk&appid=b6907d289e10d714a6e88b30761fae22",
		"Method=GET",
		"TargetFrame=https://samples.openweathermap.org/data/2.5/weather?q=London,uk&appid=b6907d289e10d714a6e88b30761fae22",
		"Referer=",
		ITEMDATA,
		LAST);

	lr_end_transaction("WeatherApi", LR_AUTO);

	return 0;
}
