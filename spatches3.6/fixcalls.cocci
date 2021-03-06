@@
identifier f;
type T;
@@
T f(...){<...
- i2c_add_adapter(...)
+0
...>}
@@
identifier f;
type T;
@@
T f(...){<...
- add_adapter(...)
+0
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-vga_get_uninterruptible(...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-pci_dev_put(...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-vga_put(...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-intel_init_quirks(...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-drm_helper_disable_unused_functions(...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-INIT_WORK(...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-setup_timer(...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-DRM_DEBUG_KMS(
+fprintf(stderr, 
...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-DRM_LOG_KMS(
+ fprintf(stderr, 
...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-printk(
+fprintf(stderr, 
...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-printk_once(
+fprintf(stderr, 
...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-DRM_INFO(
+ fprintf(stderr, 
...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-DRM_ERROR(
+fprintf(stderr, 
...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-DRM_DEBUG(
+fprintf(stderr, 
...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-DRM_DEBUG_DRIVER(
+fprintf(stderr, 
...);
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-kfree(
+freez(
...);
...>}
@ rulekz @
identifier t;
identifier f;
expression E1, E2;
type T;
@@
T f(...){<...
t = kzalloc(E1, E2);
...>}
@@
identifier rulekz.f;
expression E1, E2;
@@

- kzalloc(E1
+ allocz(E1
-  ,E2
   )
@@
identifier d;
@@
-static 
const struct pci_device_id d[] = {...};
@@
expression E1;
@@
-WARN(
+if (
E1
-,
+) fprintf(stderr, 
...);
@@
@@
-jiffies
+msecs()
@@
expression E1;
@@
-jiffies_to_msecs(
E1
-)
@@
expression E1;
@@
-msecs_to_jiffies(
E1
-)
@@
expression E1, E2;
@@
-time_after(
+(
E1
-,
+>
E2)
@@
@@
-msleep(
+mdelay(
...)
@ rulekc @
identifier t;
identifier f;
expression E1, E2, E3;
type T;
@@
T f(...){<...
t = kcalloc(E1, E2, E3);
...>}
@@
identifier rulekc.f;
expression E1, E2, E3;
@@
- kcalloc(E1, E2
+ allocz(E1 * E2
-  ,E3
   )
@ rulekr @
identifier t;
identifier f;
expression E1, E2, E3;
type T;
@@
T f(...){<...
t = krealloc(E1, E2, E3);
...>}
@@
identifier rulekr.f;
expression E1, E2, E3;
@@
- krealloc(E1, E2
+ realloc(E1, E2
-  ,E3
   )
@ rulekm @
identifier t;
identifier f;
expression E1, E2;
type T;
@@
T f(...){<...
t = kmalloc(E1, E2);
...>}
@@
identifier rulekm.f;
expression E1, E2;
@@
- kmalloc(E1 
+ malloc(E1 
-  ,E2
   )
@@
identifier f;
type T;
@@
T f(...){<...
(
-mutex_lock(...);
|
-mutex_unlock(...);
|
-mutex_init(...);
)
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-if (HAS_PCH_SPLIT(...))
{...}
-else {...}
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-if (HAS_PCH_SPLIT(...))
{...}
...>}
@@
identifier f;
type T;
@@
T f(...){<...
-if (IS_I865G(...)) {...}
...>}
@@
identifier f;
type T;
statement S;
@@
T f(...){<...
-if (IS_I865G(...)) S;
...>}
@@
expression E1;
@@
-dev_err(E1, 
+fprintf(stderr, 
...);
@@
@@
-pr_info(
+fprintf(stderr, 
...);
@@
expression E1;
@@
-dev_warn(E1, 
+fprintf(stderr, 
...);
@@
expression E;
@@
-uninitialized_var(
E
-)
@@
identifier d;
identifier v;
@@
v = 
-drm_mode_create(d)
+malloc(sizeof(struct drm_display_mode))
@@
expression e;
identifier v;
@@
v = 
-le16_to_cpu(x)
+le16toh(x)
@@
expression e;
identifier v;
@@
v = 
-cpu_to_le16(x)
+htole16(x)
@@
@@
-drm_connector_cleanup(...);
@@
@@
-drm_encoder_cleanup(...);
@@
@@
-drm_sysfs_connector_add(...);
@@
@@
-drm_mode_destroy(...);
@ ruleidr @
identifier t;
identifier f;
expression E1, E2;
type T;
@@
T f(...){<...
t = idr_pre_get(E1, E2);
...>}
@@
identifier ruleidr.f;
expression E1, E2;
@@
idr_pre_get(E1
-  ,E2
   )
@@
@@
-in_atomic(...)
+0
@@
@@
-in_dbg_master(...)
+0
@@
@@
-usleep_range(...)
@@
@@
-cond_resched(...)
@@
@@
-intel_crt_init(...)
@@
@@
-yield(...)
@@
type T;
identifier f;
@@
T f(...){<...
(
-dmi_check_system(...)
+ 0
)
...>}
@@
identifier d;
expression E;
@@
struct drm_crtc_helper_funcs d = {
-.disable = E
};
@@
@@
-spin_lock_irqsave(...);
@@
@@
-spin_lock_irqrestore(...);
@@
@@
-spin_lock_init(...);
@@
@@
-spin_unlock_irqrestore(...);
@@
@@
-i915_gem_object_pin_fence(...);
@@
@@
-i915_gem_object_pin_fence(...){...}
@@
@@
-i915_gem_object_pin_unfence(...);
@@
@@
-i915_gem_object_pin_unfence(...){...}
@@
@@
-cpu_relax(...);
@@
@@
-i915_gem_object_unpin_fence(...);
@@
@@
-pci_set_master(...);
+fprintf(stderr, "Warning: somebody tried to call pci_set_master\n");
@@
@@
-drm_property_destroy(...);
@@
@@
-drm_mode_sort(...);
@@
@@
-drm_kms_helper_poll_enable(...);
@@
@@
-unlock_fb_info(...){...}
@@
@@
-register_framebuffer(...)
+0
@@
@@
-unregister_framebuffer(...)
+0
@@
@@
-io_mapping_free(...);
@@
@@
-pci_iounmap(...);
@@
@@
-intel_gmch_remove(...);
@@
@@
-mtrr_del(...);
@@
@@
-unregister_shrinker(...);
@@
@@
-register_shrinker(...);
@@
identifier d;
@@
-drm_core_check_feature(d, DRIVER_MODESET)
+ 1
@@
@@
-pr_warn_once(
+fprintf(stderr, 
...);
@@
expression E;
@@
-assert_spin_locked(E);
@@
@@
-destroy_workqueue(...);
