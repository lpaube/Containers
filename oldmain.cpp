/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:08:44 by laube             #+#    #+#             */
/*   Updated: 2022/04/21 20:21:09 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "stack.hpp"
#include "rb_tree.hpp"
#include "map.hpp"
#include "utils.hpp"
//#include "Timer.hpp"

#include <sstream>
#include <list>
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>

#define NAMESPACE ft


void vec_assign_range(NAMESPACE::vector<int>& vreal, NAMESPACE::vector<int>& vref)
{
  vreal.assign(vref.begin(), vref.begin() + 3);
}

void vec_insert_range(NAMESPACE::vector<int>& vreal, NAMESPACE::vector<int>& vref)
{
  vreal.insert(vreal.begin(), vref.begin(), vref.begin() + 5);
}

void vec_insert_basic(NAMESPACE::vector<int>& vreal)
{
  for (NAMESPACE::vector<int>::size_type i = 0; i < 50; ++i)
  {
    vreal.insert(vreal.begin(), i);
  }
}

void generate_map_int(NAMESPACE::map<int, int>& map1)
{
  map1.insert(NAMESPACE::pair<int, int>(10, 100));
  map1.insert(NAMESPACE::pair<int, int>(20, 200));
  map1.insert(NAMESPACE::pair<int, int>(30, 300));
  map1.insert(NAMESPACE::pair<int, int>(40, 400));
  map1.insert(NAMESPACE::pair<int, int>(50, 500));
  map1.insert(NAMESPACE::pair<int, int>(60, 600));
  map1.insert(NAMESPACE::pair<int, int>(70, 700));
  map1.insert(NAMESPACE::pair<int, int>(80, 800));
  map1.insert(NAMESPACE::pair<int, int>(90, 900));
  map1.insert(NAMESPACE::pair<int, int>(11, 101));
  map1.insert(NAMESPACE::pair<int, int>(21, 201));
  map1.insert(NAMESPACE::pair<int, int>(31, 301));
  map1.insert(NAMESPACE::pair<int, int>(41, 401));
  map1.insert(NAMESPACE::pair<int, int>(51, 501));
  map1.insert(NAMESPACE::pair<int, int>(61, 601));
  map1.insert(NAMESPACE::pair<int, int>(71, 701));
  map1.insert(NAMESPACE::pair<int, int>(81, 801));
  map1.insert(NAMESPACE::pair<int, int>(91, 901));
  map1.insert(NAMESPACE::pair<int, int>(12, 102));
  map1.insert(NAMESPACE::pair<int, int>(22, 202));
  map1.insert(NAMESPACE::pair<int, int>(32, 302));
  map1.insert(NAMESPACE::pair<int, int>(42, 402));
  map1.insert(NAMESPACE::pair<int, int>(52, 502));
  map1.insert(NAMESPACE::pair<int, int>(62, 602));
  map1.insert(NAMESPACE::pair<int, int>(72, 702));
  map1.insert(NAMESPACE::pair<int, int>(82, 802));
  map1.insert(NAMESPACE::pair<int, int>(92, 902));
  map1.insert(NAMESPACE::pair<int, int>(13, 103));
  map1.insert(NAMESPACE::pair<int, int>(23, 203));
  map1.insert(NAMESPACE::pair<int, int>(33, 303));
  map1.insert(NAMESPACE::pair<int, int>(43, 403));
  map1.insert(NAMESPACE::pair<int, int>(53, 503));
  map1.insert(NAMESPACE::pair<int, int>(63, 603));
  map1.insert(NAMESPACE::pair<int, int>(73, 703));
  map1.insert(NAMESPACE::pair<int, int>(83, 803));
  map1.insert(NAMESPACE::pair<int, int>(93, 903));
  map1.insert(NAMESPACE::pair<int, int>(14, 104));
  map1.insert(NAMESPACE::pair<int, int>(24, 204));
  map1.insert(NAMESPACE::pair<int, int>(34, 304));
  map1.insert(NAMESPACE::pair<int, int>(44, 404));
  map1.insert(NAMESPACE::pair<int, int>(54, 504));
  map1.insert(NAMESPACE::pair<int, int>(64, 604));
  map1.insert(NAMESPACE::pair<int, int>(74, 704));
  map1.insert(NAMESPACE::pair<int, int>(84, 804));
  map1.insert(NAMESPACE::pair<int, int>(94, 904));
  map1.insert(NAMESPACE::pair<int, int>(15, 105));
  map1.insert(NAMESPACE::pair<int, int>(25, 205));
  map1.insert(NAMESPACE::pair<int, int>(35, 305));
  map1.insert(NAMESPACE::pair<int, int>(45, 405));
  map1.insert(NAMESPACE::pair<int, int>(55, 505));
  map1.insert(NAMESPACE::pair<int, int>(65, 605));
  map1.insert(NAMESPACE::pair<int, int>(75, 705));
  map1.insert(NAMESPACE::pair<int, int>(85, 805));
  map1.insert(NAMESPACE::pair<int, int>(95, 905));
  map1.insert(NAMESPACE::pair<int, int>(16, 106));
  map1.insert(NAMESPACE::pair<int, int>(26, 206));
  map1.insert(NAMESPACE::pair<int, int>(36, 306));
  map1.insert(NAMESPACE::pair<int, int>(46, 406));
  map1.insert(NAMESPACE::pair<int, int>(56, 506));
  map1.insert(NAMESPACE::pair<int, int>(66, 606));
  map1.insert(NAMESPACE::pair<int, int>(76, 706));
  map1.insert(NAMESPACE::pair<int, int>(86, 806));
  map1.insert(NAMESPACE::pair<int, int>(96, 906));
  map1.insert(NAMESPACE::pair<int, int>(17, 107));
  map1.insert(NAMESPACE::pair<int, int>(27, 207));
  map1.insert(NAMESPACE::pair<int, int>(37, 307));
  map1.insert(NAMESPACE::pair<int, int>(47, 407));
  map1.insert(NAMESPACE::pair<int, int>(57, 507));
  map1.insert(NAMESPACE::pair<int, int>(67, 607));
  map1.insert(NAMESPACE::pair<int, int>(77, 707));
  map1.insert(NAMESPACE::pair<int, int>(87, 807));
  map1.insert(NAMESPACE::pair<int, int>(97, 907));
  map1.insert(NAMESPACE::pair<int, int>(18, 108));
  map1.insert(NAMESPACE::pair<int, int>(28, 208));
  map1.insert(NAMESPACE::pair<int, int>(38, 308));
  map1.insert(NAMESPACE::pair<int, int>(48, 408));
  map1.insert(NAMESPACE::pair<int, int>(58, 508));
  map1.insert(NAMESPACE::pair<int, int>(68, 608));
  map1.insert(NAMESPACE::pair<int, int>(78, 708));
  map1.insert(NAMESPACE::pair<int, int>(88, 808));
  map1.insert(NAMESPACE::pair<int, int>(98, 908));
  map1.insert(NAMESPACE::pair<int, int>(19, 109));
  map1.insert(NAMESPACE::pair<int, int>(29, 209));
  map1.insert(NAMESPACE::pair<int, int>(39, 309));
  map1.insert(NAMESPACE::pair<int, int>(49, 409));
  map1.insert(NAMESPACE::pair<int, int>(59, 509));
  map1.insert(NAMESPACE::pair<int, int>(69, 609));
  map1.insert(NAMESPACE::pair<int, int>(79, 709));
  map1.insert(NAMESPACE::pair<int, int>(89, 809));
  map1.insert(NAMESPACE::pair<int, int>(99, 909));

  map1.insert(NAMESPACE::pair<int, int>(110, 1100));
  map1.insert(NAMESPACE::pair<int, int>(120, 1200));
  map1.insert(NAMESPACE::pair<int, int>(130, 1300));
  map1.insert(NAMESPACE::pair<int, int>(140, 1400));
  map1.insert(NAMESPACE::pair<int, int>(150, 1500));
  map1.insert(NAMESPACE::pair<int, int>(160, 1600));
  map1.insert(NAMESPACE::pair<int, int>(170, 1700));
  map1.insert(NAMESPACE::pair<int, int>(180, 1800));
  map1.insert(NAMESPACE::pair<int, int>(190, 1900));
  map1.insert(NAMESPACE::pair<int, int>(111, 1101));
  map1.insert(NAMESPACE::pair<int, int>(121, 1201));
  map1.insert(NAMESPACE::pair<int, int>(131, 1301));
  map1.insert(NAMESPACE::pair<int, int>(141, 1401));
  map1.insert(NAMESPACE::pair<int, int>(151, 1501));
  map1.insert(NAMESPACE::pair<int, int>(161, 1601));
  map1.insert(NAMESPACE::pair<int, int>(171, 1701));
  map1.insert(NAMESPACE::pair<int, int>(181, 1801));
  map1.insert(NAMESPACE::pair<int, int>(191, 1901));
  map1.insert(NAMESPACE::pair<int, int>(112, 1102));
  map1.insert(NAMESPACE::pair<int, int>(122, 1202));
  map1.insert(NAMESPACE::pair<int, int>(132, 1302));
  map1.insert(NAMESPACE::pair<int, int>(142, 1402));
  map1.insert(NAMESPACE::pair<int, int>(152, 1502));
  map1.insert(NAMESPACE::pair<int, int>(162, 1602));
  map1.insert(NAMESPACE::pair<int, int>(172, 1702));
  map1.insert(NAMESPACE::pair<int, int>(182, 1802));
  map1.insert(NAMESPACE::pair<int, int>(192, 1902));
  map1.insert(NAMESPACE::pair<int, int>(113, 1103));
  map1.insert(NAMESPACE::pair<int, int>(123, 1203));
  map1.insert(NAMESPACE::pair<int, int>(133, 1303));
  map1.insert(NAMESPACE::pair<int, int>(143, 1403));
  map1.insert(NAMESPACE::pair<int, int>(153, 1503));
  map1.insert(NAMESPACE::pair<int, int>(163, 1603));
  map1.insert(NAMESPACE::pair<int, int>(173, 1703));
  map1.insert(NAMESPACE::pair<int, int>(183, 1803));
  map1.insert(NAMESPACE::pair<int, int>(193, 1903));
  map1.insert(NAMESPACE::pair<int, int>(114, 1104));
  map1.insert(NAMESPACE::pair<int, int>(124, 1204));
  map1.insert(NAMESPACE::pair<int, int>(134, 1304));
  map1.insert(NAMESPACE::pair<int, int>(144, 1404));
  map1.insert(NAMESPACE::pair<int, int>(154, 1504));
  map1.insert(NAMESPACE::pair<int, int>(164, 1604));
  map1.insert(NAMESPACE::pair<int, int>(174, 1704));
  map1.insert(NAMESPACE::pair<int, int>(184, 1804));
  map1.insert(NAMESPACE::pair<int, int>(194, 1904));
  map1.insert(NAMESPACE::pair<int, int>(115, 1105));
  map1.insert(NAMESPACE::pair<int, int>(125, 1205));
  map1.insert(NAMESPACE::pair<int, int>(135, 1305));
  map1.insert(NAMESPACE::pair<int, int>(145, 1405));
  map1.insert(NAMESPACE::pair<int, int>(155, 1505));
  map1.insert(NAMESPACE::pair<int, int>(165, 1605));
  map1.insert(NAMESPACE::pair<int, int>(175, 1705));
  map1.insert(NAMESPACE::pair<int, int>(185, 1805));
  map1.insert(NAMESPACE::pair<int, int>(195, 1905));
  map1.insert(NAMESPACE::pair<int, int>(116, 1106));
  map1.insert(NAMESPACE::pair<int, int>(126, 1206));
  map1.insert(NAMESPACE::pair<int, int>(136, 1306));
  map1.insert(NAMESPACE::pair<int, int>(146, 1406));
  map1.insert(NAMESPACE::pair<int, int>(156, 1506));
  map1.insert(NAMESPACE::pair<int, int>(166, 1606));
  map1.insert(NAMESPACE::pair<int, int>(176, 1706));
  map1.insert(NAMESPACE::pair<int, int>(186, 1806));
  map1.insert(NAMESPACE::pair<int, int>(196, 1906));
  map1.insert(NAMESPACE::pair<int, int>(117, 1107));
  map1.insert(NAMESPACE::pair<int, int>(127, 1207));
  map1.insert(NAMESPACE::pair<int, int>(137, 1307));
  map1.insert(NAMESPACE::pair<int, int>(147, 1407));
  map1.insert(NAMESPACE::pair<int, int>(157, 1507));
  map1.insert(NAMESPACE::pair<int, int>(167, 1607));
  map1.insert(NAMESPACE::pair<int, int>(177, 1707));
  map1.insert(NAMESPACE::pair<int, int>(187, 1807));
  map1.insert(NAMESPACE::pair<int, int>(197, 1907));
  map1.insert(NAMESPACE::pair<int, int>(118, 1108));
  map1.insert(NAMESPACE::pair<int, int>(128, 1208));
  map1.insert(NAMESPACE::pair<int, int>(138, 1308));
  map1.insert(NAMESPACE::pair<int, int>(148, 1408));
  map1.insert(NAMESPACE::pair<int, int>(158, 1508));
  map1.insert(NAMESPACE::pair<int, int>(168, 1608));
  map1.insert(NAMESPACE::pair<int, int>(178, 1708));
  map1.insert(NAMESPACE::pair<int, int>(188, 1808));
  map1.insert(NAMESPACE::pair<int, int>(198, 1908));
  map1.insert(NAMESPACE::pair<int, int>(119, 1109));
  map1.insert(NAMESPACE::pair<int, int>(129, 1209));
  map1.insert(NAMESPACE::pair<int, int>(139, 1309));
  map1.insert(NAMESPACE::pair<int, int>(149, 1409));
  map1.insert(NAMESPACE::pair<int, int>(159, 1509));
  map1.insert(NAMESPACE::pair<int, int>(169, 1609));
  map1.insert(NAMESPACE::pair<int, int>(179, 1709));
  map1.insert(NAMESPACE::pair<int, int>(189, 1809));
  map1.insert(NAMESPACE::pair<int, int>(199, 1909));

  map1.insert(NAMESPACE::pair<int, int>(210, 2100));
  map1.insert(NAMESPACE::pair<int, int>(220, 2200));
  map1.insert(NAMESPACE::pair<int, int>(230, 2300));
  map1.insert(NAMESPACE::pair<int, int>(240, 2400));
  map1.insert(NAMESPACE::pair<int, int>(250, 2500));
  map1.insert(NAMESPACE::pair<int, int>(260, 2600));
  map1.insert(NAMESPACE::pair<int, int>(270, 2700));
  map1.insert(NAMESPACE::pair<int, int>(280, 2800));
  map1.insert(NAMESPACE::pair<int, int>(290, 2900));
  map1.insert(NAMESPACE::pair<int, int>(211, 2101));
  map1.insert(NAMESPACE::pair<int, int>(221, 2201));
  map1.insert(NAMESPACE::pair<int, int>(231, 2301));
  map1.insert(NAMESPACE::pair<int, int>(241, 2401));
  map1.insert(NAMESPACE::pair<int, int>(251, 2501));
  map1.insert(NAMESPACE::pair<int, int>(261, 2601));
  map1.insert(NAMESPACE::pair<int, int>(271, 2701));
  map1.insert(NAMESPACE::pair<int, int>(281, 2801));
  map1.insert(NAMESPACE::pair<int, int>(291, 2901));
  map1.insert(NAMESPACE::pair<int, int>(212, 2102));
  map1.insert(NAMESPACE::pair<int, int>(222, 2202));
  map1.insert(NAMESPACE::pair<int, int>(232, 2302));
  map1.insert(NAMESPACE::pair<int, int>(242, 2402));
  map1.insert(NAMESPACE::pair<int, int>(252, 2502));
  map1.insert(NAMESPACE::pair<int, int>(262, 2602));
  map1.insert(NAMESPACE::pair<int, int>(272, 2702));
  map1.insert(NAMESPACE::pair<int, int>(282, 2802));
  map1.insert(NAMESPACE::pair<int, int>(292, 2902));
  map1.insert(NAMESPACE::pair<int, int>(213, 2103));
  map1.insert(NAMESPACE::pair<int, int>(223, 2203));
  map1.insert(NAMESPACE::pair<int, int>(233, 2303));
  map1.insert(NAMESPACE::pair<int, int>(243, 2403));
  map1.insert(NAMESPACE::pair<int, int>(253, 2503));
  map1.insert(NAMESPACE::pair<int, int>(263, 2603));
  map1.insert(NAMESPACE::pair<int, int>(273, 2703));
  map1.insert(NAMESPACE::pair<int, int>(283, 2803));
  map1.insert(NAMESPACE::pair<int, int>(293, 2903));
  map1.insert(NAMESPACE::pair<int, int>(214, 2104));
  map1.insert(NAMESPACE::pair<int, int>(224, 2204));
  map1.insert(NAMESPACE::pair<int, int>(234, 2304));
  map1.insert(NAMESPACE::pair<int, int>(244, 2404));
  map1.insert(NAMESPACE::pair<int, int>(254, 2504));
  map1.insert(NAMESPACE::pair<int, int>(264, 2604));
  map1.insert(NAMESPACE::pair<int, int>(274, 2704));
  map1.insert(NAMESPACE::pair<int, int>(284, 2804));
  map1.insert(NAMESPACE::pair<int, int>(294, 2904));
  map1.insert(NAMESPACE::pair<int, int>(215, 2105));
  map1.insert(NAMESPACE::pair<int, int>(225, 2205));
  map1.insert(NAMESPACE::pair<int, int>(235, 2305));
  map1.insert(NAMESPACE::pair<int, int>(245, 2405));
  map1.insert(NAMESPACE::pair<int, int>(255, 2505));
  map1.insert(NAMESPACE::pair<int, int>(265, 2605));
  map1.insert(NAMESPACE::pair<int, int>(275, 2705));
  map1.insert(NAMESPACE::pair<int, int>(285, 2805));
  map1.insert(NAMESPACE::pair<int, int>(295, 2905));
  map1.insert(NAMESPACE::pair<int, int>(216, 2106));
  map1.insert(NAMESPACE::pair<int, int>(226, 2206));
  map1.insert(NAMESPACE::pair<int, int>(236, 2306));
  map1.insert(NAMESPACE::pair<int, int>(246, 2406));
  map1.insert(NAMESPACE::pair<int, int>(256, 2506));
  map1.insert(NAMESPACE::pair<int, int>(266, 2606));
  map1.insert(NAMESPACE::pair<int, int>(276, 2706));
  map1.insert(NAMESPACE::pair<int, int>(286, 2806));
  map1.insert(NAMESPACE::pair<int, int>(296, 2906));
  map1.insert(NAMESPACE::pair<int, int>(217, 2107));
  map1.insert(NAMESPACE::pair<int, int>(227, 2207));
  map1.insert(NAMESPACE::pair<int, int>(237, 2307));
  map1.insert(NAMESPACE::pair<int, int>(247, 2407));
  map1.insert(NAMESPACE::pair<int, int>(257, 2507));
  map1.insert(NAMESPACE::pair<int, int>(267, 2607));
  map1.insert(NAMESPACE::pair<int, int>(277, 2707));
  map1.insert(NAMESPACE::pair<int, int>(287, 2807));
  map1.insert(NAMESPACE::pair<int, int>(297, 2907));
  map1.insert(NAMESPACE::pair<int, int>(218, 2108));
  map1.insert(NAMESPACE::pair<int, int>(228, 2208));
  map1.insert(NAMESPACE::pair<int, int>(238, 2308));
  map1.insert(NAMESPACE::pair<int, int>(248, 2408));
  map1.insert(NAMESPACE::pair<int, int>(258, 2508));
  map1.insert(NAMESPACE::pair<int, int>(268, 2608));
  map1.insert(NAMESPACE::pair<int, int>(278, 2708));
  map1.insert(NAMESPACE::pair<int, int>(288, 2808));
  map1.insert(NAMESPACE::pair<int, int>(298, 2908));
  map1.insert(NAMESPACE::pair<int, int>(219, 2109));
  map1.insert(NAMESPACE::pair<int, int>(229, 2209));
  map1.insert(NAMESPACE::pair<int, int>(239, 2309));
  map1.insert(NAMESPACE::pair<int, int>(249, 2409));
  map1.insert(NAMESPACE::pair<int, int>(259, 2509));
  map1.insert(NAMESPACE::pair<int, int>(269, 2609));
  map1.insert(NAMESPACE::pair<int, int>(279, 2709));
  map1.insert(NAMESPACE::pair<int, int>(289, 2809));
  map1.insert(NAMESPACE::pair<int, int>(299, 2909));

  map1.insert(NAMESPACE::pair<int, int>(310, 3100));
  map1.insert(NAMESPACE::pair<int, int>(320, 3200));
  map1.insert(NAMESPACE::pair<int, int>(330, 3300));
  map1.insert(NAMESPACE::pair<int, int>(340, 3400));
  map1.insert(NAMESPACE::pair<int, int>(350, 3500));
  map1.insert(NAMESPACE::pair<int, int>(360, 3600));
  map1.insert(NAMESPACE::pair<int, int>(370, 3700));
  map1.insert(NAMESPACE::pair<int, int>(380, 3800));
  map1.insert(NAMESPACE::pair<int, int>(390, 3900));
  map1.insert(NAMESPACE::pair<int, int>(311, 3101));
  map1.insert(NAMESPACE::pair<int, int>(321, 3201));
  map1.insert(NAMESPACE::pair<int, int>(331, 3301));
  map1.insert(NAMESPACE::pair<int, int>(341, 3401));
  map1.insert(NAMESPACE::pair<int, int>(351, 3501));
  map1.insert(NAMESPACE::pair<int, int>(361, 3601));
  map1.insert(NAMESPACE::pair<int, int>(371, 3701));
  map1.insert(NAMESPACE::pair<int, int>(381, 3801));
  map1.insert(NAMESPACE::pair<int, int>(391, 3901));
  map1.insert(NAMESPACE::pair<int, int>(312, 3102));
  map1.insert(NAMESPACE::pair<int, int>(322, 3202));
  map1.insert(NAMESPACE::pair<int, int>(332, 3302));
  map1.insert(NAMESPACE::pair<int, int>(342, 3402));
  map1.insert(NAMESPACE::pair<int, int>(352, 3502));
  map1.insert(NAMESPACE::pair<int, int>(362, 3602));
  map1.insert(NAMESPACE::pair<int, int>(372, 3702));
  map1.insert(NAMESPACE::pair<int, int>(382, 3802));
  map1.insert(NAMESPACE::pair<int, int>(392, 3902));
  map1.insert(NAMESPACE::pair<int, int>(313, 3103));
  map1.insert(NAMESPACE::pair<int, int>(323, 3203));
  map1.insert(NAMESPACE::pair<int, int>(333, 3303));
  map1.insert(NAMESPACE::pair<int, int>(343, 3403));
  map1.insert(NAMESPACE::pair<int, int>(353, 3503));
  map1.insert(NAMESPACE::pair<int, int>(363, 3603));
  map1.insert(NAMESPACE::pair<int, int>(373, 3703));
  map1.insert(NAMESPACE::pair<int, int>(383, 3803));
  map1.insert(NAMESPACE::pair<int, int>(393, 3903));
  map1.insert(NAMESPACE::pair<int, int>(314, 3104));
  map1.insert(NAMESPACE::pair<int, int>(324, 3204));
  map1.insert(NAMESPACE::pair<int, int>(334, 3304));
  map1.insert(NAMESPACE::pair<int, int>(344, 3404));
  map1.insert(NAMESPACE::pair<int, int>(354, 3504));
  map1.insert(NAMESPACE::pair<int, int>(364, 3604));
  map1.insert(NAMESPACE::pair<int, int>(374, 3704));
  map1.insert(NAMESPACE::pair<int, int>(384, 3804));
  map1.insert(NAMESPACE::pair<int, int>(394, 3904));
  map1.insert(NAMESPACE::pair<int, int>(315, 3105));
  map1.insert(NAMESPACE::pair<int, int>(325, 3205));
  map1.insert(NAMESPACE::pair<int, int>(335, 3305));
  map1.insert(NAMESPACE::pair<int, int>(345, 3405));
  map1.insert(NAMESPACE::pair<int, int>(355, 3505));
  map1.insert(NAMESPACE::pair<int, int>(365, 3605));
  map1.insert(NAMESPACE::pair<int, int>(375, 3705));
  map1.insert(NAMESPACE::pair<int, int>(385, 3805));
  map1.insert(NAMESPACE::pair<int, int>(395, 3905));
  map1.insert(NAMESPACE::pair<int, int>(316, 3106));
  map1.insert(NAMESPACE::pair<int, int>(326, 3206));
  map1.insert(NAMESPACE::pair<int, int>(336, 3306));
  map1.insert(NAMESPACE::pair<int, int>(346, 3406));
  map1.insert(NAMESPACE::pair<int, int>(356, 3506));
  map1.insert(NAMESPACE::pair<int, int>(366, 3606));
  map1.insert(NAMESPACE::pair<int, int>(376, 3706));
  map1.insert(NAMESPACE::pair<int, int>(386, 3806));
  map1.insert(NAMESPACE::pair<int, int>(396, 3906));
  map1.insert(NAMESPACE::pair<int, int>(317, 3107));
  map1.insert(NAMESPACE::pair<int, int>(327, 3207));
  map1.insert(NAMESPACE::pair<int, int>(337, 3307));
  map1.insert(NAMESPACE::pair<int, int>(347, 3407));
  map1.insert(NAMESPACE::pair<int, int>(357, 3507));
  map1.insert(NAMESPACE::pair<int, int>(367, 3607));
  map1.insert(NAMESPACE::pair<int, int>(377, 3707));
  map1.insert(NAMESPACE::pair<int, int>(387, 3807));
  map1.insert(NAMESPACE::pair<int, int>(397, 3907));
  map1.insert(NAMESPACE::pair<int, int>(318, 3108));
  map1.insert(NAMESPACE::pair<int, int>(328, 3208));
  map1.insert(NAMESPACE::pair<int, int>(338, 3308));
  map1.insert(NAMESPACE::pair<int, int>(348, 3408));
  map1.insert(NAMESPACE::pair<int, int>(358, 3508));
  map1.insert(NAMESPACE::pair<int, int>(368, 3608));
  map1.insert(NAMESPACE::pair<int, int>(378, 3708));
  map1.insert(NAMESPACE::pair<int, int>(388, 3808));
  map1.insert(NAMESPACE::pair<int, int>(398, 3908));
  map1.insert(NAMESPACE::pair<int, int>(319, 3109));
  map1.insert(NAMESPACE::pair<int, int>(329, 3209));
  map1.insert(NAMESPACE::pair<int, int>(339, 3309));
  map1.insert(NAMESPACE::pair<int, int>(349, 3409));
  map1.insert(NAMESPACE::pair<int, int>(359, 3509));
  map1.insert(NAMESPACE::pair<int, int>(369, 3609));
  map1.insert(NAMESPACE::pair<int, int>(379, 3709));
  map1.insert(NAMESPACE::pair<int, int>(389, 3809));
  map1.insert(NAMESPACE::pair<int, int>(399, 3909));

  map1.insert(NAMESPACE::pair<int, int>(410, 4100));
  map1.insert(NAMESPACE::pair<int, int>(420, 4200));
  map1.insert(NAMESPACE::pair<int, int>(430, 4300));
  map1.insert(NAMESPACE::pair<int, int>(440, 4400));
  map1.insert(NAMESPACE::pair<int, int>(450, 4500));
  map1.insert(NAMESPACE::pair<int, int>(460, 4600));
  map1.insert(NAMESPACE::pair<int, int>(470, 4700));
  map1.insert(NAMESPACE::pair<int, int>(480, 4800));
  map1.insert(NAMESPACE::pair<int, int>(490, 4900));
  map1.insert(NAMESPACE::pair<int, int>(411, 4101));
  map1.insert(NAMESPACE::pair<int, int>(421, 4201));
  map1.insert(NAMESPACE::pair<int, int>(431, 4301));
  map1.insert(NAMESPACE::pair<int, int>(441, 4401));
  map1.insert(NAMESPACE::pair<int, int>(451, 4501));
  map1.insert(NAMESPACE::pair<int, int>(461, 4601));
  map1.insert(NAMESPACE::pair<int, int>(471, 4701));
  map1.insert(NAMESPACE::pair<int, int>(481, 4801));
  map1.insert(NAMESPACE::pair<int, int>(491, 4901));
  map1.insert(NAMESPACE::pair<int, int>(412, 4102));
  map1.insert(NAMESPACE::pair<int, int>(422, 4202));
  map1.insert(NAMESPACE::pair<int, int>(432, 4302));
  map1.insert(NAMESPACE::pair<int, int>(442, 4402));
  map1.insert(NAMESPACE::pair<int, int>(452, 4502));
  map1.insert(NAMESPACE::pair<int, int>(462, 4602));
  map1.insert(NAMESPACE::pair<int, int>(472, 4702));
  map1.insert(NAMESPACE::pair<int, int>(482, 4802));
  map1.insert(NAMESPACE::pair<int, int>(492, 4902));
  map1.insert(NAMESPACE::pair<int, int>(413, 4103));
  map1.insert(NAMESPACE::pair<int, int>(423, 4203));
  map1.insert(NAMESPACE::pair<int, int>(433, 4303));
  map1.insert(NAMESPACE::pair<int, int>(443, 4403));
  map1.insert(NAMESPACE::pair<int, int>(453, 4503));
  map1.insert(NAMESPACE::pair<int, int>(463, 4603));
  map1.insert(NAMESPACE::pair<int, int>(473, 4703));
  map1.insert(NAMESPACE::pair<int, int>(483, 4803));
  map1.insert(NAMESPACE::pair<int, int>(493, 4903));
  map1.insert(NAMESPACE::pair<int, int>(414, 4104));
  map1.insert(NAMESPACE::pair<int, int>(424, 4204));
  map1.insert(NAMESPACE::pair<int, int>(434, 4304));
  map1.insert(NAMESPACE::pair<int, int>(444, 4404));
  map1.insert(NAMESPACE::pair<int, int>(454, 4504));
  map1.insert(NAMESPACE::pair<int, int>(464, 4604));
  map1.insert(NAMESPACE::pair<int, int>(474, 4704));
  map1.insert(NAMESPACE::pair<int, int>(484, 4804));
  map1.insert(NAMESPACE::pair<int, int>(494, 4904));
  map1.insert(NAMESPACE::pair<int, int>(415, 4105));
  map1.insert(NAMESPACE::pair<int, int>(425, 4205));
  map1.insert(NAMESPACE::pair<int, int>(435, 4305));
  map1.insert(NAMESPACE::pair<int, int>(445, 4405));
  map1.insert(NAMESPACE::pair<int, int>(455, 4505));
  map1.insert(NAMESPACE::pair<int, int>(465, 4605));
  map1.insert(NAMESPACE::pair<int, int>(475, 4705));
  map1.insert(NAMESPACE::pair<int, int>(485, 4805));
  map1.insert(NAMESPACE::pair<int, int>(495, 4905));
  map1.insert(NAMESPACE::pair<int, int>(416, 4106));
  map1.insert(NAMESPACE::pair<int, int>(426, 4206));
  map1.insert(NAMESPACE::pair<int, int>(436, 4306));
  map1.insert(NAMESPACE::pair<int, int>(446, 4406));
  map1.insert(NAMESPACE::pair<int, int>(456, 4506));
  map1.insert(NAMESPACE::pair<int, int>(466, 4606));
  map1.insert(NAMESPACE::pair<int, int>(476, 4706));
  map1.insert(NAMESPACE::pair<int, int>(486, 4806));
  map1.insert(NAMESPACE::pair<int, int>(496, 4906));
  map1.insert(NAMESPACE::pair<int, int>(417, 4107));
  map1.insert(NAMESPACE::pair<int, int>(427, 4207));
  map1.insert(NAMESPACE::pair<int, int>(437, 4307));
  map1.insert(NAMESPACE::pair<int, int>(447, 4407));
  map1.insert(NAMESPACE::pair<int, int>(457, 4507));
  map1.insert(NAMESPACE::pair<int, int>(467, 4607));
  map1.insert(NAMESPACE::pair<int, int>(477, 4707));
  map1.insert(NAMESPACE::pair<int, int>(487, 4807));
  map1.insert(NAMESPACE::pair<int, int>(497, 4907));
  map1.insert(NAMESPACE::pair<int, int>(418, 4108));
  map1.insert(NAMESPACE::pair<int, int>(428, 4208));
  map1.insert(NAMESPACE::pair<int, int>(438, 4308));
  map1.insert(NAMESPACE::pair<int, int>(448, 4408));
  map1.insert(NAMESPACE::pair<int, int>(458, 4508));
  map1.insert(NAMESPACE::pair<int, int>(468, 4608));
  map1.insert(NAMESPACE::pair<int, int>(478, 4708));
  map1.insert(NAMESPACE::pair<int, int>(488, 4808));
  map1.insert(NAMESPACE::pair<int, int>(498, 4908));
  map1.insert(NAMESPACE::pair<int, int>(419, 4109));
  map1.insert(NAMESPACE::pair<int, int>(429, 4209));
  map1.insert(NAMESPACE::pair<int, int>(439, 4309));
  map1.insert(NAMESPACE::pair<int, int>(449, 4409));
  map1.insert(NAMESPACE::pair<int, int>(459, 4509));
  map1.insert(NAMESPACE::pair<int, int>(469, 4609));
  map1.insert(NAMESPACE::pair<int, int>(479, 4709));
  map1.insert(NAMESPACE::pair<int, int>(489, 4809));
  map1.insert(NAMESPACE::pair<int, int>(499, 4909));
  map1.erase(429);
}

template <typename Key, typename Value>
void map_upper_bound(NAMESPACE::map<Key, Value>& map1)
{
  for (typename NAMESPACE::map<Key, Value>::iterator it = map1.begin()
      ; it != map1.end()
      ; ++it)
  {
    map1.upper_bound(it->first);
  }
}

int main(void)
{
 NAMESPACE::map<int, int> m1;

 generate_map_int(m1);

 map_upper_bound(m1);

 std::cerr << "this is size" << m1.size() << std::endl;

 return 0;
}

