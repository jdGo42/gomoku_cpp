#ifndef STATS_HPP
# define STATS_HPP

# include <unordered_map>
# include <iostream>
# include <string>
# include <chrono>

struct sStat {
	int	nbCalls;
	std::chrono::duration<double>	totalExecTime;
	std::chrono::duration<double>	avgExecTime;
	std::chrono::duration<double>	minExecTime;
	std::chrono::duration<double>	maxExecTime;
	std::chrono::high_resolution_clock::time_point	startExecTime;
};

class Stats {
	public:
		Stats();
		~Stats();
		static void	startStats(std::string name);
		static void	endStats(std::string name);
		static void	printStats();
		static std::unordered_map<std::string, struct sStat> stats;
};

// getStats for Clasic function ___________________

template<typename RetT, typename ...Args>
RetT getStats(std::string name, RetT (&func)(Args...), Args... args) {
    Stats::startStats(name);
	RetT res = func(args...);
    Stats::endStats(name);
	return res;
}
template<typename ...Args>
void getStatsVoid(std::string name, void (&func)(Args...), Args... args) {
    Stats::startStats(name);
	func(args...);
    Stats::endStats(name);
}


// getStats for Member function ___________________

template<typename RetT, typename ClassT, typename ...Args>
void getStatsM(std::string name, ClassT &obj, RetT (ClassT::*func)(Args...), Args... args) {
    Stats::startStats(name);
	RetT res = (obj.*func)(args...);
    Stats::endStats(name);
	return res;
}
template<typename ClassT, typename ...Args>
void getStatsMVoid(std::string name, ClassT &obj, void (ClassT::*func)(Args...), Args... args) {
    Stats::startStats(name);
	(obj.*func)(args...);
    Stats::endStats(name);
}

#endif
