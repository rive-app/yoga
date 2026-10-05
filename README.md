# yoga

Our fork of [yoga](https://github.com/facebook/yoga) 2.0.1 with CSS grid
backported, imported from `rive-app/yoga` branch `rive_changes_v2_0_1_4_grid`
(dd288d29db). Change it here, in the same PR as the runtime code that needs it.

After changing anything in this folder, run `dev/yoga_ref.sh` and commit the
updated `packages/runtime/dependencies/yoga.ref`. Merging to master publishes
this folder to the `rive` branch of `rive-app/yoga` under that tag, which is
what mirrors of the runtime build.
