#include "importinventory.hpp"

#include <components/esm/esmreader.hpp>

#include <components/esm/loadcont.hpp>

namespace ESSImport
{

    void Inventory::load(ESM::ESMReader &esm)
    {
        while (esm.isNextSub("NPCO"))
        {
            ESM::ContItem contItem;
            esm.getHT(contItem);

            InventoryItem item;
            item.mId = contItem.mItem.toString();
            item.mCount = contItem.mCount;

            if (esm.isNextSub("XIDX"))
                esm.skipHSub();

            std::string script = esm.getHNOString("SCRI");
            // script variables?
            // unsure if before or after ESM::CellRef
            if (!script.empty())
            {
                if (esm.isNextSub("SLCS"))
                    esm.skipHSub();
                if (esm.isNextSub("SLSD")) // Short Data?
                    esm.skipHSub();
                if (esm.isNextSub("SLFD")) // Float Data?
                    esm.skipHSub();
            }

            // for XSOL and XCHG seen so far, but probably others too
            item.ESM::CellRef::loadData(esm);

            item.mCondition = -1;
            // FIXME: for Lights, this is actually a float
            esm.getHNOT(item.mCondition, "XHLT");
            mItems.push_back(item);
        }

        // equipped items
        while (esm.isNextSub("WIDX"))
        {
            // note: same item can be equipped 2 items (e.g. 2 rings)
            // and will be *stacked* in the NPCO list, unlike openmw!
            esm.getSubHeader();
            int itemIndex; // index of the item in the NPCO list
            esm.getT(itemIndex);

            // appears to be a relative index for only the *possible* slots this item can be equipped in,
            // i.e. 0 most of the time, unlike openmw slot enum index
            int slotIndex;
            esm.getT(slotIndex);
        }
    }

}
