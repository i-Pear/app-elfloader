#include <uk/syscall.h>
#include <uk/plat/syscall.h>
#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
#include <uk/plat/tls.h>
#include <uk/thread.h>
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */
#include <uk/assert.h>
#include <uk/print.h>
#include <uk/essentials.h>

long __kernel_vsyscall6(long syscall_nr, long arg0, long arg1, long arg2, long arg3, long arg4, long arg5)
{
#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	struct uk_thread *self;
	__uptr orig_tlsp;

	/* Activate Unikraft TLS */
	orig_tlsp = ukplat_tlsp_get();
	self = uk_thread_current();
	UK_ASSERT(self);
	ukplat_tlsp_set(self->uktlsp);
	_uk_syscall_ultlsp = orig_tlsp;
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	long ret = uk_syscall6_r(syscall_nr,
				 arg0, arg1, arg2,
				 arg3, arg4, arg5);

#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	uk_thread_uktls_var(self, _uk_syscall_ultlsp) = 0x0;

	/* Restore original TLS only if it was _NOT_
	 * changed by the system call handler
	 */
	if (likely(ukplat_tlsp_get() == self->uktlsp)) {
		ukplat_tlsp_set(orig_tlsp);
	} else {
		uk_pr_debug("System call updated userland TLS pointer register to %p (before: %p)\n",
			    (void *) orig_tlsp, (void *) ukplat_tlsp_get());
	}
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	return ret;
}

long __kernel_vsyscall5(long syscall_nr, long arg0, long arg1, long arg2, long arg3, long arg4)
{
#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	struct uk_thread *self;
	__uptr orig_tlsp;

	/* Activate Unikraft TLS */
	orig_tlsp = ukplat_tlsp_get();
	self = uk_thread_current();
	UK_ASSERT(self);
	ukplat_tlsp_set(self->uktlsp);
	_uk_syscall_ultlsp = orig_tlsp;
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	long ret = uk_syscall5_r(syscall_nr,
				 arg0, arg1, arg2,
				 arg3, arg4);

#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	uk_thread_uktls_var(self, _uk_syscall_ultlsp) = 0x0;

	/* Restore original TLS only if it was _NOT_
	 * changed by the system call handler
	 */
	if (likely(ukplat_tlsp_get() == self->uktlsp)) {
		ukplat_tlsp_set(orig_tlsp);
	} else {
		uk_pr_debug("System call updated userland TLS pointer register to %p (before: %p)\n",
			    (void *) orig_tlsp, (void *) ukplat_tlsp_get());
	}
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	return ret;
}

long __kernel_vsyscall4(long syscall_nr, long arg0, long arg1, long arg2, long arg3)
{
#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	struct uk_thread *self;
	__uptr orig_tlsp;

	/* Activate Unikraft TLS */
	orig_tlsp = ukplat_tlsp_get();
	self = uk_thread_current();
	UK_ASSERT(self);
	ukplat_tlsp_set(self->uktlsp);
	_uk_syscall_ultlsp = orig_tlsp;
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	long ret = uk_syscall4_r(syscall_nr,
				 arg0, arg1, arg2,
				 arg3);

#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	uk_thread_uktls_var(self, _uk_syscall_ultlsp) = 0x0;

	/* Restore original TLS only if it was _NOT_
	 * changed by the system call handler
	 */
	if (likely(ukplat_tlsp_get() == self->uktlsp)) {
		ukplat_tlsp_set(orig_tlsp);
	} else {
		uk_pr_debug("System call updated userland TLS pointer register to %p (before: %p)\n",
			    (void *) orig_tlsp, (void *) ukplat_tlsp_get());
	}
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	return ret;
}

long __kernel_vsyscall3(long syscall_nr, long arg0, long arg1, long arg2)
{
#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	struct uk_thread *self;
	__uptr orig_tlsp;

	/* Activate Unikraft TLS */
	orig_tlsp = ukplat_tlsp_get();
	self = uk_thread_current();
	UK_ASSERT(self);
	ukplat_tlsp_set(self->uktlsp);
	_uk_syscall_ultlsp = orig_tlsp;
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	long ret = uk_syscall3_r(syscall_nr,
				 arg0, arg1, arg2);

#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	uk_thread_uktls_var(self, _uk_syscall_ultlsp) = 0x0;

	/* Restore original TLS only if it was _NOT_
	 * changed by the system call handler
	 */
	if (likely(ukplat_tlsp_get() == self->uktlsp)) {
		ukplat_tlsp_set(orig_tlsp);
	} else {
		uk_pr_debug("System call updated userland TLS pointer register to %p (before: %p)\n",
			    (void *) orig_tlsp, (void *) ukplat_tlsp_get());
	}
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	return ret;
}

long __kernel_vsyscall2(long syscall_nr, long arg0, long arg1)
{
#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	struct uk_thread *self;
	__uptr orig_tlsp;

	/* Activate Unikraft TLS */
	orig_tlsp = ukplat_tlsp_get();
	self = uk_thread_current();
	UK_ASSERT(self);
	ukplat_tlsp_set(self->uktlsp);
	_uk_syscall_ultlsp = orig_tlsp;
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	long ret = uk_syscall2_r(syscall_nr,
				 arg0, arg1);

#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	uk_thread_uktls_var(self, _uk_syscall_ultlsp) = 0x0;

	/* Restore original TLS only if it was _NOT_
	 * changed by the system call handler
	 */
	if (likely(ukplat_tlsp_get() == self->uktlsp)) {
		ukplat_tlsp_set(orig_tlsp);
	} else {
		uk_pr_debug("System call updated userland TLS pointer register to %p (before: %p)\n",
			    (void *) orig_tlsp, (void *) ukplat_tlsp_get());
	}
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	return ret;
}

long __kernel_vsyscall1(long syscall_nr, long arg0)
{
#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	struct uk_thread *self;
	__uptr orig_tlsp;

	/* Activate Unikraft TLS */
	orig_tlsp = ukplat_tlsp_get();
	self = uk_thread_current();
	UK_ASSERT(self);
	ukplat_tlsp_set(self->uktlsp);
	_uk_syscall_ultlsp = orig_tlsp;
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	long ret = uk_syscall1_r(syscall_nr,
				 arg0);

#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	uk_thread_uktls_var(self, _uk_syscall_ultlsp) = 0x0;

	/* Restore original TLS only if it was _NOT_
	 * changed by the system call handler
	 */
	if (likely(ukplat_tlsp_get() == self->uktlsp)) {
		ukplat_tlsp_set(orig_tlsp);
	} else {
		uk_pr_debug("System call updated userland TLS pointer register to %p (before: %p)\n",
			    (void *) orig_tlsp, (void *) ukplat_tlsp_get());
	}
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	return ret;
}

long __kernel_vsyscall0(long syscall_nr)
{
#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	struct uk_thread *self;
	__uptr orig_tlsp;

	/* Activate Unikraft TLS */
	orig_tlsp = ukplat_tlsp_get();
	self = uk_thread_current();
	UK_ASSERT(self);
	ukplat_tlsp_set(self->uktlsp);
	_uk_syscall_ultlsp = orig_tlsp;
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	long ret = uk_syscall0_r(syscall_nr);

#if CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS
	uk_thread_uktls_var(self, _uk_syscall_ultlsp) = 0x0;

	/* Restore original TLS only if it was _NOT_
	 * changed by the system call handler
	 */
	if (likely(ukplat_tlsp_get() == self->uktlsp)) {
		ukplat_tlsp_set(orig_tlsp);
	} else {
		uk_pr_debug("System call updated userland TLS pointer register to %p (before: %p)\n",
			    (void *) orig_tlsp, (void *) ukplat_tlsp_get());
	}
#endif /* CONFIG_LIBSYSCALL_SHIM_HANDLER_ULTLS */

	return ret;
}
