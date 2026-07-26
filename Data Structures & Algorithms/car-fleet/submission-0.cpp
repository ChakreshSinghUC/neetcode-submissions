class Solution {
public:
    int carFleet(
        int target,
        vector<int>& position,
        vector<int>& speed
    ) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Closest car to the target comes first.
        sort(cars.rbegin(), cars.rend());

        stack<double> fleetTimes;

        for (auto [pos, spd] : cars) {
            double currentTime =
                static_cast<double>(target - pos) / spd;

            /*
             A greater time means this car cannot catch
             the fleet immediately ahead.
            */
            if (fleetTimes.empty() ||
                currentTime > fleetTimes.top()) {

                fleetTimes.push(currentTime);
            }

            /*
             If currentTime <= fleetTimes.top(),
             this car catches the fleet ahead.

             We do not push it because it becomes part
             of that existing fleet.
            */
        }

        return fleetTimes.size();
    }
};