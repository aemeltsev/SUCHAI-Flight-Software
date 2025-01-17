/*                                 SUCHAI
 *                      NANOSATELLITE FLIGHT SOFTWARE
 *
 *      Copyright 2019, Carlos Gonzalez Cortes, carlgonz@uchile.cl
 *      Copyright 2019, Ignacio Ibanez Aliaga, ignacio.ibanez@usach.cl
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "osScheduler.h"

const static char *tag = "osScheduler";

/**
 * starts the scheduler of the system operating
 */
void osScheduler(os_thread* threads_id, int n_threads)
{
    LOGI(tag, "Linux scheduler: waiting threads")

    int i;
    for(i = 0; i < n_threads; i++){
        pthread_join(threads_id[i], NULL);
    }
    
    /* FIXME: In case of error the application should be closed */
    /* FIXME: Catch term or exit or kill signal to do a clean exit */
    exit(0);
}
