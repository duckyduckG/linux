// SPDX-License-Identifier: MIT
#include <engine/msenc.h>

#include <nvif/class.h>

static void
gk104_msenc_init(struct nvkm_falcon *msenc)
{
	struct nvkm_device *device = msenc->engine.subdev.device;
	nvkm_wr32(device, 0x1c2010, 0x0000fff2);
	nvkm_wr32(device, 0x1c201c, 0x0000fff2);
}

static const struct nvkm_falcon_func
gk104_msenc = {
	.init = gk104_msenc_init,
	.sclass = {
		{ -1, -1, GK104_MSENC },
		{}
	}
};

int
gk104_msenc_new(struct nvkm_device *device, enum nvkm_subdev_type type, int inst,
		struct nvkm_engine **pengine)
{
	return nvkm_falcon_new_(&gk104_msenc, device, type, inst, true, 0x1c2000, pengine);
}
