/*
 * Copyright (C) 2005-2013 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2013 MaNGOSZero <https:// github.com/mangos/zero>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOS_GUARDAI_H
#define MANGOS_GUARDAI_H

#include "CreatureAI.h"
#include "ObjectGuid.h"
#include "Timer.h"

class Creature;

class MANGOS_DLL_DECL GuardAI : public CreatureAI
{
        enum GuardState
        {
            STATE_NORMAL = 1,
            STATE_LOOK_AT_VICTIM = 2
        };

    public:

        explicit GuardAI(Creature* c);

        void MoveInLineOfSight(Unit*) override;
        void AttackStart(Unit*) override;
        void EnterEvadeMode() override;
        void JustDied(Unit*) override;
        bool IsVisible(Unit*) const override;

        void UpdateAI(const uint32) override;
        static int Permissible(const Creature*);

    private:
        ObjectGuid i_victimGuid;
        GuardState i_state;
        TimeTracker i_tracker;
};
#endif
