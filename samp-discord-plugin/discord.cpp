#include "discord.h"
#include <string>
namespace Discord
{
	static void ready(const DiscordUser* request) {}

	static void errored(int errorCode, const char* message) {}

	static void disconnected(int errorCode, const char* message) {}

	static void joinGame(const char* joinSecret) {}

	static void spectateGame(const char* spectateSecret) {}

	static void joinRequest(const DiscordUser* request) {}

	void initialize()
	{
		DiscordEventHandlers handlers = { 0 };
		handlers.ready = ready;
		handlers.errored = errored;
		handlers.disconnected = disconnected;
		handlers.joinGame = joinGame;
		handlers.spectateGame = spectateGame;
		handlers.joinRequest = joinRequest;
		Discord_Initialize("1150266362451742781", &handlers, 1, nullptr);
		Discord_ClearPresence();
	}

	void update(const time_t time, const char* state, const char* details, const char* image, const char* imageDetails, const char* infoDetails, const char* discordUrl)
	{
		DiscordRichPresence discordPresence = { 0 };
		discordPresence.state = state;
		discordPresence.details = details;
		discordPresence.startTimestamp = time;
		discordPresence.largeImageKey = image;
		discordPresence.largeImageText = imageDetails;
		discordPresence.smallImageKey = "info";
		discordPresence.smallImageText = infoDetails;

		if (std::strlen(discordUrl) > 5) {
			discordPresence.button1Label = "¡Unete a nuestro discord!";
			discordPresence.button1Url = discordUrl;
		}

		Discord_UpdatePresence(&discordPresence);

		
	}
}
