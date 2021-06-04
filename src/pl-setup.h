/*  Part of SWI-Prolog

    Author:        Jan Wielemaker
    E-mail:        J.Wielemaker@vu.nl
    WWW:           http://www.swi-prolog.org
    Copyright (c)  1985-2020, University of Amsterdam
                              VU University Amsterdam
			      CWI, Amsterdam
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in
       the documentation and/or other materials provided with the
       distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
    COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
    ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

#include "pl-incl.h"

#ifndef _PL_SETUP_H
#define _PL_SETUP_H

		 /*******************************
		 *    FUNCTION DECLARATIONS	*
		 *******************************/

int		setupProlog(void);
int		endCritical__LD(ARG1_LD);
void		dispatch_signal(int sig, int sync);
handler_t	set_sighandler(int sig, handler_t func);
void		blockSignals(sigset_t *mask);
void		allSignalMask(sigset_t *set);
void		unblockSignals(sigset_t *mask);
void		unblockSignal(int sig);
void		blockSignal(int sig);
void		resetSignals(void);
void		cleanupSignals(void);
int		handleSignals(ARG1_LD);
void		terminate_on_signal(int signo);

int		initPrologStacks(size_t limit);
void		initPrologLocalData(ARG1_LD);
void		deallocateStacks(void);
bool		restoreStack(Stack s);
void		trimStacks(int resize ARG_LD);
void		emptyStacks(void);
void		freeStacks(ARG1_LD);
void		freePrologLocalData(PL_local_data_t *ld);
int		ensure_room_stack(Stack s, size_t n, int ex);
int		trim_stack(Stack s);
int		set_stack_limit(size_t limit);
const char *	signal_name(int sig);

#endif /*_PL_SETUP_H*/