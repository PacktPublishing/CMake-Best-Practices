#include <SI/velocity.h>
#include <SI/stream.h>

#include <iostream>

using namespace SI::literals;

int main(int argc, char**)
{
    constexpr auto speed_of_a_swallow_in_m = 11.2_m_p_s;
    constexpr SI::kilometre_per_hour_t<long double> speed_in_km = speed_of_a_swallow_in_m;

    std::cout << "Did you know that an unladen swallow travels at approximately " << speed_of_a_swallow_in_m << " which is " << speed_in_km << "\n";
    
}