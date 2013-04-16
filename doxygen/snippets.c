/** [sample code] */
#include <libpldraw.h>
#include <libplepaper.h>

int main(void)
{
	struct pldraw *pldraw;
	struct plep *plep;
	struct plep_rect area;
	int xres;
	int yres;

	/* Initialise the pldraw instance for libpldraw */
	pldraw = pldraw_init(NULL);

	/* Initialise the plep instance for libplepaper */
	plep = plep_init(NULL, NULL);

	/* Get the framebuffer resolution */
	xres = pldraw_get_xres(pldraw);
	yres = pldraw_get_yres(pldraw);

	/* Enable synchronous e-paper updates to avoid merging updates */
	plep_set_opt(plep, PLEP_SYNC_UPDATE, 1);

	/* Clear the screen with white and update it with refresh waveform */
	pldraw_fill_screen(pldraw, pldraw_get_grey(pldraw, 0xFF));
	plep_update_screen(plep, plep_get_wfid(plep, PLEP_REFRESH));

	/* Calculate a rectangular area in the center of the screen */
	area.a.x = xres / 4;
	area.a.y = yres / 4;
	area.b.x = xres * 3 / 4;
	area.b.y = yres * 3 / 4;

	/* Fill the rectangle with black and update it with a mono waveform */
	pldraw_fill_rect(pldraw, pldraw_get_grey(pldraw, 0x00), &area);
	plep_update(plep, &area, plep_get_wfid(plep, PLEP_DELTA"/"PLEP_MONO));

	/* Free the resources associated with pldraw and plep instances */
	pldraw_free(pldraw);
	plep_free(plep);

	return 0;
}
/** [sample code] */
