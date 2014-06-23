// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Elephancoin Developers
// Copyright (c) 2014 AluminiumCoin Developer - CCP
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
//(0, uint256("0x"))
(0,     uint256("0x5c5a2c6d59ef93212407c7fef081543bde06adfd24aed1d22da67ceb3444bd11"))
(1,     uint256("0xbde1affe6853fa49f80c13c29c929777e831941ac993cae4ce6608817f4b3d8e"))
(10,    uint256("0xe2e4eb0938c10f36e82d8480459efdbb4e404fc8bbf8876ed837119e43a8d5e8"))
(20,    uint256("0xf1aa89b2278d5c772c663bd814dac9b96e3da3b7c563f2f97ca101804afb40a9"))
(30,    uint256("0x3adcb672517b1c8f75430289d5b56d86cf410b11e959b4ce7518c4f22e7dd991"))
(33,    uint256("0xfd2c0ecb617214cc533718a2f52897ca597ab962fe435eb5570c68d1eba41668")) //"time" : 1403564846,
;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;

//### Default Value
return hash == i->second;

//### Produce Value
//return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

//### Default Value
return mapCheckpoints.rbegin()->first;

//### Produce Value
//return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
//### Default Value
return t->second;

//### Produce Value
//return NULL;
        }
        return NULL;
    }
}
