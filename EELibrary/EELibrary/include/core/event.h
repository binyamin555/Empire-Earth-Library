#pragma once

#include <filesystem>

#include <functional>


namespace ee::modding::core {
	template <typename ...Ts>
	struct Event {
		using EventSubscription = size_t;

		inline EventSubscription Subscribe(std::function<void(Ts...)> func) {
			EventSubscription token = nextToken++;
			callbacks[token] = func;
			return token;
		}

		void Unsubscribe(EventSubscription token) {
			callbacks.erase(token);
		}

		void Invoke(Ts... args) {
			for (const auto& [token, callback] : callbacks) {
				callback(args...);
			}
		}

		void InvokeAsync(Ts... args) {
			std::thread([&]() {
				Invoke(args...);
				}).detach();
		}

		EventSubscription operator+=(std::function<void(Ts...)> func) {
			return Subscribe(func);
		}

		void operator-=(EventSubscription token) {
			Unsubscribe(token);
		}

		void operator()(Ts... args) {
			Invoke(args...);
		}

	private:
		std::unordered_map<EventSubscription, std::function<void(Ts...)>> callbacks;
		EventSubscription nextToken = 0;
	};
}
